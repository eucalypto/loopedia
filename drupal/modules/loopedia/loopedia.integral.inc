<?php

/**
 * @file
 * Contains callback functions for Loopedia integral submission form
 */



/**
* Callback function for the first step of the integral submission form.
*/
function loopedia_integral_first_step(&$form, &$form_state)
{
 // Define array of fields, that shall be shown
 $elements_to_show = array(
   'lop_input',
 );
 //
 _loopedia_display_fields($elements_to_show, $form, $form_state);




 // Buttons:
 $form['actions']['next'] = array(
   '#type' => 'submit',
   '#value' => 'Next >>',
   '#submit' => array('loopedia_integral_next_submit_1'),
   '#validate' => array('loopedia_integral_next_validate_1'),
 );
 $form['actions']['submit']['#attributes']['class']['hide_me'] = 'element-hidden';
}




/**
 * Adjusts which fields will be displayed
 *
 * @param &$fields_to_show array
 *   This is an array of strings. Each string is the name of the field
 *   that you want to be displayed.
 */
function _loopedia_display_fields(&$fields_to_show, &$form, &$form_state)
{
  // Store array of fieldnames in $form_state, if it does not exist.
  if (!isset($form_state['all_fields']))
  {
    // The following two numbers are just copies of the definitions in
    // _loopedia_integral_installed_fields() in "loopedia.install" and
    // thus should be the same.
    $max_num_prop = 21;
    $max_num_leg = 20;
    $num_expr = 5;

    // This array is trivially associative because later we want to
    // erase some elements.
    $fieldnames = array(
      'lop_comment' => 'lop_comment',
      'lop_input' => 'lop_input',
      'lop_nickel' => 'lop_nickel',
      'lop_vertex_number' => 'lop_vertex_number',
      'lop_literature_arxiv' => 'lop_literature_arxiv',
      'lop_literature_publication' => 'lop_literature_publication',
      'lop_int_mass_shell_leg_num' => 'lop_int_mass_shell_leg_num',
      'lop_leg_number' => 'lop_leg_number',
      'lop_light_like_leg_number' => 'lop_light_like_leg_number',
      'lop_loop_number' => 'lop_loop_number',
      'lop_mass_scale_number' => 'lop_mass_scale_number',
      'lop_massless_propagator_number' => 'lop_massless_propagator_number',
      'lop_massive_propagator_number' => 'lop_massive_propagator_number',
      'lop_off_shell_leg_number' => 'lop_off_shell_leg_number',
      'lop_propagator_number' => 'lop_propagator_number',
    );
    // Add the external leg virtualities to $fieldnames :
    for ($i = 1; $i <= $max_num_leg; $i++)
    {
      $fieldnames['lop_ext_leg_' . $i . '_virt'] = 'lop_ext_leg_' . $i . '_virt';
    }
    // Add the mass and power fields for the propagators:
    for ($i = 1; $i <= $max_num_prop; $i++)
    {
      $fieldnames['lop_propagator_' . $i . '_mass'] = 'lop_propagator_' . $i . '_mass';
      $fieldnames['lop_propagator_' . $i . '_power'] = 'lop_propagator_' . $i . '_power';
    }
    for ($i = 1; $i <= $num_expr; $i++)
    {
      $fieldnames['lop_expr_type_' . $i] = 'lop_expr_type_' . $i;
      $fieldnames['lop_expr_dim_' . $i] = 'lop_expr_dim_' . $i;
      $fieldnames['lop_expr_body_' . $i] = 'lop_expr_body_' . $i;
    }

    $form_state['all_fields'] = $fieldnames;
  }

  // Make a working copy of all fieldnames
  $fields_to_hide = $form_state['all_fields'];

  // Delete fieldnames from working copy that we want to display
  foreach ($fields_to_show as $fieldname)
  {
    unset($fields_to_hide[$fieldname]);
  }

  // Make remaining fields invisible:
  foreach ($fields_to_hide as $hide_me)
  {
    $form[$hide_me]['#attributes']['class']['hide_me'] = 'element-hidden';
    // $form[$hide_me]['#pre_render'] = array('loopedia_empty_array');

    // The use of '#pre_render' produces unwanted consequences. If you
    // use it to hide a field in a multi-step form, this field will be
    // ignored for the next step. So you lose this information and the
    // user has to re-type the field, if he goes back.
  }

}




/**
 * Validate handler for loopedia_integral_first_step next button
 *
 * It might become important, in which order the validation functions
 * are executed. Then, you should experiment with it.
 *
 */
function loopedia_integral_next_validate_1(&$form, &$form_state)
{
  $graph_id = &$form_state['values']['lop_input']['und'][0]['value'];

  if (strpos($graph_id, '|') !==  FALSE)
  {
    // $graph_id contains a '|' character. Therefore it is probably a
    // Nickel index.
    // Begin of checking of the given nickel index.
    $nickel_value_given = &$graph_id;

    // Check the formal structure of the given index: it shall only
    // contain "e", "0-9" and "|".
    if (preg_match('/^[e0-9A-Z\|]*$/', $nickel_value_given) !== 1)
    {
      form_set_error('graph_id', t('Your Nickel Index seems to contain other characters than the allowed: "e", "0-9", "A-Z", "|".'));
    }


    // Check, if given Nickel index is correct(minimal).

    // When drupal executes a script, it starts in the project path e.g.
    // /var/www/html/drupal_project/ , where the "sites/" folder is.
    $exec1 = "python sites/default/scripts/minimalnickel.py " .
               escapeshellarg($nickel_value_given) .
               " 2>&1";
    $nickel_value_correct = trim(shell_exec($exec1)); // Correct Nickel
                            // Index calculated by script.  trim() was
                            // needed here because shell_exec() produces
                            // one unwanted whitespace at the end of the
                            // output string


    if ( strlen($nickel_value_given) != strlen($nickel_value_correct) )
    {
      // GraphState outputs a (long) error message if the nickel string
      // argument is wrong according to the convention. So if the output
      // of the script has not the same length as the given nickel
      // string, something went wrong.

      form_set_error('graph_id', t(
        'Your nickel index "@ni_given" seems to be wrong. Please check if it is according to the conventions.',
        array(
        '@ni_given' => $nickel_value_given,
        )
      ));
    }
    elseif ( $nickel_value_given != $nickel_value_correct )
    {
      // If the given string has the same length as the outupt but is
      // not equal, then the given nickel index is not minimal.

      // So we write the corret nickel index to the appropriate places:
      // $form_state['values'] storet the real value that is used
      // further.
      $form_state['values']['lop_nickel']['und'][0]['value'] = $nickel_value_correct;
      // $form_state['input'] apparently stores the user input. This is
      // printed on the screen.
      $form_state['input']['lop_nickel']['und'][0]['value'] = $nickel_value_correct;
      // // form_set_value() does not work as I expect.
      // form_set_value($form['nickel_adjalist']['lop_nickel'], 'blabla', $form_state);


      // Now we print out a message, that the Nickel Index was changed
      // to the correct version:
      drupal_set_message(t('The given nickel index: "@ni_given" is not correct (minimal). It was replaced by the correct (minimal) Nickel index: <strong>"@ni_correct"</strong>.',
        array(
          '@ni_given' => $nickel_value_given,
          '@ni_correct' => $nickel_value_correct,
        )
      ));
    }
    else
    {
      $form_state['input']['lop_nickel']['und'][0]['value'] = $graph_id;
      $form_state['values']['lop_nickel']['und'][0]['value'] = $graph_id;
      drupal_set_message(t('The Nickel index "@nickel" is correct!',
        array('@nickel' => $nickel_value_correct)
      ));
    }
  }
  // End of checking the Nickel index.
  else
  {
    // $graph_id is probably not a Nickel Index.
    // Begin of the check of the given adjacency list

    $adjalist = &$graph_id;
    // Check if the given adjacency list string contains forbidden
    // characters. Allowed ones are ",", "-", "[", "]", "0-9", " "
    // See http://www.rexegg.com/regex-php.html
    if (preg_match('/^[,\[\]0-9\s-]*$/', $adjalist) !== 1)
    {
      form_set_error('graph_id', t(
      'Your adjacency list seems to contain not allowed characters. The allowed ones are: "[comma]", "-", "[", "]", "0-9", "[whitespace]"'
    ));
    }



    // Calculate the Nickel index from the given Adjacency List
    $exec0 = "python sites/default/scripts/edgelist_to_nickel.py " .
              escapeshellarg($adjalist) .
              " 2>&1";
    $generated_nickel = trim(shell_exec($exec0));



    // If the script outputs more than one line (nickel index), then
    // there must have been an error. So if the output $generated_nickel
    // contains a newline character ("\n" == PHP_EOL), an error is
    // displayed.
    // http://stackoverflow.com/questions/9437121/how-to-detect-if-a-string-has-a-new-line-break-in-it
    if (strpos($generated_nickel, PHP_EOL) !== FALSE)
    {
      form_set_error('graph_id', t(
        "There seems to be a problem with your adjacency list."
      ));
    }
    else
    {
      // The adjacency list and generated nickel index seem to be all
      // right. So we can write the nickel index to the appropriate
      // places:
      $form_state['values']['lop_nickel']['und'][0]['value'] = $generated_nickel;
      $form_state['input']['lop_nickel']['und'][0]['value'] = $generated_nickel;
    }

    // End of check of the given adjacency list.
  }
}
// End of loopedia_integral_next_validate_1()



/**
 * Submit handler for loopedia_integral_first_step next button.
 */
function loopedia_integral_next_submit_1(&$form, &$form_state)
{
  $nickel = $form_state['values']['lop_nickel']['und'][0]['value'];
  // Generate Picture to Nickel Index
  $image_path = "sites/default/files/nickel_generated/tmp/" .
                  uniqid($nickel);
                 // this is the path to the dot file the image (svg)
                 // file will have an extra ending of ".svg"
  $script_path = "sites/default/scripts/neato_from_nickel.py";
  $exec2 = escapeshellcmd("python $script_path " . $nickel . " $image_path");
  exec($exec2);
  // Save image path in 'lop_picture_path'. $image_path looks like
  // 'sites/default/files/...'. We have to prefix this with something
  // like 'http://localhost/loopediatest/' in order to get an "absoulte"
  // path to the file. This is necessary because while editing a node,
  // drupal starts with the path
  // 'http://localhost/loopediatest/node/52/edit', for some reason. So
  // we need an absolute path.
  //
  // http://localhost/loopediatest is the base url for my test drupal
  // installation. To make this code portable, use the global variable
  // $GLOBALS['base_url'], which stores exactly what we need.
  $form_state['values']['lop_picture_path']['und'][0]['value'] = $GLOBALS['base_url'] . '/' . $image_path . ".svg";
  $form_state['input']['lop_picture_path']['und'][0]['value'] = $GLOBALS['base_url'] . '/' . $image_path . ".svg";





  // Extract information out of the Nickel Index string and save it to
  // the appropriate fields:
  $legs = substr_count($nickel, 'e');
  $form_state['values']['lop_leg_number']['und'][0]['value'] = $legs;
  $form_state['input']['lop_leg_number']['und'][0]['value'] = $legs;

  $propagators = preg_match_all('~[0-9A-Z]~', $nickel);
  $form_state['values']['lop_propagator_number']['und'][0]['value'] = $propagators;
  $form_state['input']['lop_propagator_number']['und'][0]['value'] = $propagators;

  $vertices = substr_count($nickel, '|');
  $form_state['values']['lop_vertex_number']['und'][0]['value'] = $vertices;
  $form_state['input']['lop_vertex_number']['und'][0]['value'] = $vertices;

  $loops = $propagators - $vertices + 1;
  $form_state['values']['lop_loop_number']['und'][0]['value'] = $loops;
  $form_state['input']['lop_loop_number']['und'][0]['value'] = $loops;



  // We set 'step' to 2 such that when the form gets build next time,
  // it will build the second step
  $form_state['step'] = 2;
  $form_state['rebuild'] = TRUE;
}





// ********************************************************************
// Second step:

/**
 * Callback function for the second step of the integral sumbission form.
 */
function loopedia_integral_second_step(&$form, &$form_state)
{
  $elements_to_show = array(
    // 'lop_nickel',
    // 'lop_leg_number',
    // 'lop_vertex_number',
    // 'lop_loop_number',
    // 'lop_propagator_number',
  );
  $num_legs = $form_state['values']['lop_leg_number']['und'][0]['value'];
  for ($i = 1; $i <= $num_legs; $i++)
  {
    $elements_to_show[] = 'lop_ext_leg_' . $i . '_virt';
  }
  //
  $num_prop = $form_state['values']['lop_propagator_number']['und'][0]['value'];
  for ($i = 1; $i <= $num_prop; $i++)
  {
    $elements_to_show[] = 'lop_propagator_' . $i . '_mass';
    $elements_to_show[] = 'lop_propagator_' . $i . '_power';
  }

  _loopedia_display_fields($elements_to_show, $form, $form_state);


  // Display calculated numbers in a fieldset. This way, the user cannot
  // change them.
  $form['display_calc_topo'] = array(
    '#type' => 'fieldset',
    '#title' => 'Topological numbers for the integral',
    '#description' => '
    <ul>
    <li>Nickel Index: ' .
      $form_state['values']['lop_nickel']['und'][0]['value'] . '</li>
    <li>Number of legs:  ' .
      $form_state['values']['lop_leg_number']['und'][0]['value'] . '</li>
    <li>Number of vertices: ' .
      $form_state['values']['lop_vertex_number']['und'][0]['value'] . '</li>
    <li>Number of loops: ' .
      $form_state['values']['lop_loop_number']['und'][0]['value'] . '</li>
    <li>Number of propagators: ' .
      $form_state['values']['lop_propagator_number']['und'][0]['value'] . '</li>
    </ul>',
  );
  // Store this fieldset in $form_state for next steps
  $form_state['display_calc_topo'] = $form['display_calc_topo'];


  // Display generated Feynman Graph
  $form['feynman_graph'] = array(
    '#type' => 'markup',
    '#markup' => '<img src="'.
      $form_state['values']['lop_picture_path']['und'][0]['value'] .
      ' "alt="alternative text">',
    '#weight' => 10,
  );

  // Propagators:

  $form['propagators'] = array(
    '#type' => 'fieldset',
    '#title' => 'Properties of Propagators',
    '#description' => 'Please set masses and powers of propagators.',
    '#weight' => 11,
    '#collapsible' => FALSE,
    // Let fields in this fieldset be displayed horizontally according
    // to
    // http://drupal.stackexchange.com/questions/7954/horizontal-form-elements
    '#attributes' => array('class' => array('container-inline')),
  );

  $props = $form_state['values']['lop_propagator_number']['und'][0]['value'];
  for ($i = 1; $i <= $props; $i++)
  {
    $form['propagators']['propagator' . $i] = array(
      '#type' => 'fieldset',
      '#title' => 'Propagator ' . $i . ' (P' . $i . ')',
      '#description' => '',
      '#collapsible' => FALSE,
      '#weight' => 10 + $i,
    );

    // Delete standard allowed choices and set new sensible ones
    unset($form['lop_propagator_' . $i . '_mass']['und']['#options']);
    $opts = &$form['lop_propagator_' . $i . '_mass']['und']['#options'];
    // $opts['_none'] =  '- None -';
    $opts['massless'] = 'massless';
    for ($j = 1; $j <= $i; $j++)
    {
      $opts['m' . $j] = 'm' . $j;
    }

    // Copy field definition to fieldset and delete original entry
    $form['propagators']['propagator' . $i]['lop_propagator_' . $i . '_mass'] = $form['lop_propagator_' . $i . '_mass'];
    unset($form['lop_propagator_' . $i . '_mass']);

    // Mass:

    // Make required
    $form['lop_propagator_' . $i . '_power']['und'][0]['value']['#required'] = TRUE;

    // Set power to '1', if it is not already filled. This is meant to
    // set a default value. (Using '#default_value' did not work, for
    // some unknown reason.)
    $pow = &$form_state['input']['lop_propagator_' . $i . '_power']['und'][0]['value'];
    if (empty($pow))
    {
      $pow = '1';
    }

    // Copy definition to fieldset and delete original:
    $form['propagators']['propagator' . $i]['lop_propagator_' . $i . '_power'] = $form['lop_propagator_' . $i . '_power'];
    unset($form['lop_propagator_' . $i . '_power']);
  }


  // The same Feynman graph again
  $form['feynman_graph_2'] = $form['feynman_graph'];
  $form['feynman_graph_2']['#weight'] = 13;

  // Legs:

  $form['leg_virtuality'] = array(
    '#type' => 'fieldset',
    '#title' => 'Virtualities of external legs',
    '#description' => 'Choose the virtuality of the external legs. The choices are:
       <ul>
        <li>light-like : p^2 = 0</li>
        <li>on_internal_mass_shell : p^2 &ne; 0. But p is on a mass shell of one of the (internal) propagators: p^2 = m_j.</li>
        <li>off-shell: p is not light like and also not on one of the internal mass shells.</li>
      </ul> ',
    '#collapsible' => FALSE,
    '#weight' => 50,
  );
  //
  $legs = $form_state['values']['lop_leg_number']['und'][0]['value'];
  for ($i = 1; $i <= $legs; $i++)
  {
    // Make field required
    // $form['lop_ext_leg_' . $i . '_virt']['und']['#required'] = TRUE;

    // Delete original options and define new ones. We need only as many
    // mass options as there are propagators.
    unset($form['lop_ext_leg_' . $i . '_virt']['und']['#options']);
    $opts = &$form['lop_ext_leg_' . $i . '_virt']['und']['#options'];
    $opts['light-like'] = 'light-like';
    $opts['off-shell'] = 'off-shell';
    for ($j = 1; $j <= $props; $j++)
    {
      $opts['m' . $j . '^2'] = 'm' . $j . '^2';
    }

    // Copy definiton to fieldset and delete old one:
    $form['leg_virtuality']['lop_ext_leg_' . $i . '_virt'] = $form['lop_ext_leg_' . $i . '_virt'];
    unset($form['lop_ext_leg_' . $i . '_virt']);
  }



  // Buttons:

  $form['actions']['back'] = array(
    '#type' => 'submit',
    '#value' => t('<< Back'),
    '#submit' => array('loopedia_integral_back_submit_2'),
    //
    // We don't want to validate the fields because they will be
    // validated once the user goes forward. #limit_validation_errors()
    // takes an array of elements that will be validated. Everything
    // else will not be validated. See
    // https://api.drupal.org/api/drupal/developer!topics!forms_api_reference.html/7#limit_validation_errors
    //
    // This should be used carefully in multi-step forms. Especially if
    // you have a multi-step form which computes something out of the
    // $form_state['values'][...]. If you use '#limit_validation_errors'
    // on a button to go back one step, there won't be any
    // $form_state['values'][...]. This is why we don't use it in the
    // button from step 3 to step 2.
    '#limit_validation_errors' => array(),
  );

  $form['actions']['next'] = array(
    '#type' => 'submit',
    '#value' => 'Next >>',
    '#submit' => array('loopedia_integral_next_submit_2'),
    // '#validate' => array('form_example_tutorial_8_next_validate'),
  );
  $form['actions']['submit']['#attributes']['class']['hide_me'] = 'element-hidden';
}

/**
 * Submit handler for loopedia_integral_second_step next button.
 */
function loopedia_integral_next_submit_2(&$form, &$form_state)
{
  // Calculate numbers for popagators:
  //
  $props_massless = 0;
  $props_massive = 0;
  $props_mass_scales = 0;
  $scales = array();
  //
  $num_prop =  $form_state['values']['lop_propagator_number']['und'][0]['value'];
  for ($i = 1; $i <= $num_prop; $i++)
  {
    $mass = $form_state['values']['lop_propagator_' . $i . '_mass']['und'][0]['value'];
    if ($mass == 'massless')
    {
      $props_massless++;
    }
    else
    {
      $props_massive++;
      if ( !in_array($mass, $scales) )
      {
        $scales[] = $mass;
        $props_mass_scales++;
      }
    }
  }
  // Write calculated values to $form_state['input'][...] and
  // $form_state['values'][...]
  foreach (array('input', 'values') as $foo)
  {
    $form_state[$foo]['lop_massless_propagator_number']['und'][0]['value'] = $props_massless;
    $form_state[$foo]['lop_massive_propagator_number']['und'][0]['value'] = $props_massive;
    $form_state[$foo]['lop_mass_scale_number']['und'][0]['value'] = $props_mass_scales;
  }


  // Calculate numbers for legs:
  //
  $legs_light = 0;
  $legs_offsh = 0;
  $legs_intmass = 0;
  //
  $num_legs = $form_state['values']['lop_leg_number']['und'][0]['value'];
  for ($i = 1; $i <= $num_legs; $i++)
  {
    $virt = $form_state['values']['lop_ext_leg_' . $i . '_virt']['und'][0]['value'];
    switch ($virt)
    {
      case 'light-like':
        $legs_light++;
        break;
      case 'off-shell':
        $legs_offsh++;
        break;
      default:
        $legs_intmass++;
        break;
    }
  }
  //
  // Write calculated values to $form_state['input'][...] and
  // $form_state['values'][...]
  foreach (array('input', 'values') as $foo)
  {
    $form_state[$foo]['lop_light_like_leg_number']['und'][0]['value'] = $legs_light;
    $form_state[$foo]['lop_off_shell_leg_number']['und'][0]['value'] = $legs_offsh;
    $form_state[$foo]['lop_int_mass_shell_leg_num']['und'][0]['value'] = $legs_intmass;
  }





  $form_state['step'] = 3;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for loopedia_integral_second_step back button.
 */
function loopedia_integral_back_submit_2(&$form, &$form_state)
{
  $form_state['step'] = 1;
  $form_state['rebuild'] = TRUE;
}



/**
 * Callback function for the third step of the integral sumbission form.
 */
function loopedia_integral_third_step(&$form, &$form_state)
{
  $num_expr = 5;

  $fields_to_show = array(
    'lop_literature_arxiv',
    'lop_literature_publication',
    'lop_comment',
  );

  for ($i = 1; $i <= $num_expr; $i++)
  {
    $fields_to_show[] = 'lop_expr_dim_' . $i;
    $fields_to_show[] = 'lop_expr_body_' . $i;
    $fields_to_show[] = 'lop_expr_type_' . $i;
  }
  _loopedia_display_fields($fields_to_show, $form, $form_state);

  // Topology numbers block:
  $form['display_calc_topo'] = $form_state['display_calc_topo'];

  // Coloring numbers block:
  $form['display_calc_color'] = array(
    '#type' => 'fieldset',
    '#title' => 'Numbers from coloring',
    '#description' => '
    <ul>
    <li>Number of light-like legs: ' .
      $form_state['values']['lop_light_like_leg_number']['und'][0]['value'] . '</li>
    <li>Number of legs on an internal mass shell:  ' .
      $form_state['values']['lop_int_mass_shell_leg_num']['und'][0]['value'] . '</li>
    <li>Number of off-shell legs: ' .
      $form_state['values']['lop_off_shell_leg_number']['und'][0]['value'] . '</li>
    <li>Number of massless propagators: ' .
      $form_state['values']['lop_massless_propagator_number']['und'][0]['value'] . '</li>
    <li>Number of massive propagators: ' .
      $form_state['values']['lop_massive_propagator_number']['und'][0]['value'] . '</li>
    <li>Number of (internal) mass scales: ' .
      $form_state['values']['lop_mass_scale_number']['und'][0]['value'] . '</li>
    </ul>',
  );

  for ($i = 1; $i <= $num_expr; $i++)
  {
    $form['expression' . $i] = array(
      '#type' => 'fieldset',
      '#title' => 'Input ' . $i,
      '#description' => 'Here, you can provide a sort of result of the integral ("input"). Please also choose the type and dimensionality ("Valid in"), if applicable.<br>
        Your input can be the prefactor in an expansion in epsilon. Then choose the corresponding power in the "Type of input". Your input also can be more general, or just an explanation.<br>
        If you want to comment or clarify your inputs, please use the "Comment"-field below.',
      '#weight' => 14+$i,
    );
    $form['expression' . $i]['lop_expr_type_' . $i] = $form['lop_expr_type_' . $i];
    unset($form['lop_expr_type_' . $i]);

    $form['expression' . $i]['lop_expr_dim_' . $i] = $form['lop_expr_dim_' . $i];
    unset($form['lop_expr_dim_' . $i]);

    $form['expression' . $i]['lop_expr_body_' . $i] = $form['lop_expr_body_' . $i];
    unset($form['lop_expr_body_' . $i]);

  }

  for ($i = 2; $i <= $num_expr; $i++)
  {
    $form['expression' . $i]['#collapsible'] = TRUE;
    $form['expression' . $i]['#collapsed'] = TRUE;
    // $form['expression' . $i]['#states'] = array(
    //   'visible' => array(
    //     ':textfield[name^="lop_literature_arxiv"]' => array('empty' => FALSE),
    //   ),
    // );
  }



  // Buttons:

  $form['actions']['back'] = array(
    '#type' => 'submit',
    '#value' => t('<< Back'),
    '#submit' => array('loopedia_integral_back_submit_3'),
    // '#limit_validation_errors' => array(),
  );

  // Add custom save submit handler to first place
  array_unshift($form['actions']['submit']['#submit'], 'loopedia_integral_save_submit');
}


/**
 * Submit handler for loopedia_integral_third_step back button.
 */
function loopedia_integral_back_submit_3(&$form, &$form_state)
{
  $form_state['step'] = 2;
  $form_state['rebuild'] = TRUE;
}


/**
 * Submit handler for loopedia_integral_third_step submit button.
 */
function loopedia_integral_save_submit(&$form, &$form_state)
{
  // Generaded Picture:

  // Generadet pictures are stored in a tmp-folder during the integral
  // submit process. Here, the generaded picture is copied to the real
  // location.

  // Make reference to stored path
  $path_old = &$form_state['values']['lop_picture_path']['und'][0]['value'];
  // Use global variable $GLOBALS['base_url'], which stores the url base
  // of the drupal installation.
  $baseurl = $GLOBALS['base_url'] . '/';

  // Remove base_url string from path to get file path
  $path_old = str_replace($baseurl, '', $path_old);
  // Write new path by removing '/tmp/' from it
  $path_new = str_replace('/tmp/', '/', $path_old);

  // Copy picture to new path.
  $cmd = escapeshellcmd("cp $path_old $path_new");
  exec($cmd);

  // Write new path to $form_state (reference)
  $path_old = $baseurl . $path_new;
}
