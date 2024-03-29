<?php
/**
 * @file
 * loopedia_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function loopedia_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_lop_integral-comment_body'.
  $field_instances['comment-comment_node_lop_integral-comment_body'] = array(
    'bundle' => 'comment_node_lop_integral',
    'default_value' => array(
      0 => array(
        'value' => 'None',
      ),
    ),
    'deleted' => 0,
    'description' => 'This field is required by the Comment module. But we are not using it. This is why it is removed from the submit form in nickelplay_form_comment_node_lop_integral_form_alter(). See https://www.drupal.org/node/1038652

And for some crazy reason, this field has to be required. So we set a default value that will be saved as a dummy value.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment unused',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_lop_integral-field_comment_arxiv'.
  $field_instances['comment-comment_node_lop_integral-field_comment_arxiv'] = array(
    'bundle' => 'comment_node_lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'field_comment_arxiv',
    'label' => 'arXiv Identifier',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_lop_integral-field_comment_comment'.
  $field_instances['comment-comment_node_lop_integral-field_comment_comment'] = array(
    'bundle' => 'comment_node_lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Here, you can write comments that are not in your file. This is the place to specify details of your result or clarify important points.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'field_comment_comment',
    'label' => 'Comment',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_lop_integral-field_comment_file'.
  $field_instances['comment-comment_node_lop_integral-field_comment_file'] = array(
    'bundle' => 'comment_node_lop_integral',
    'deleted' => 0,
    'description' => 'Please upload a file. It can be a text file, a Mathematca file or any other file that stores the Result in a useful way.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'field_comment_file',
    'label' => 'Result File',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'integral_files',
      'file_extensions' => 'txt',
      'max_filesize' => '30 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_lop_integral-field_comment_publication'.
  $field_instances['comment-comment_node_lop_integral-field_comment_publication'] = array(
    'bundle' => 'comment_node_lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Here you can provide further Publication details. Like journal publications.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'field_comment_publication',
    'label' => 'Publication',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_color_num-field_lop_int_mass_shell_leg_num'.
  $field_instances['field_collection_item-field_lop_color_num-field_lop_int_mass_shell_leg_num'] = array(
    'bundle' => 'field_lop_color_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_int_mass_shell_leg_num',
    'label' => 'Number of legs on an internal mass shell',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_color_num-field_lop_light_like_leg_number'.
  $field_instances['field_collection_item-field_lop_color_num-field_lop_light_like_leg_number'] = array(
    'bundle' => 'field_lop_color_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_light_like_leg_number',
    'label' => 'Number of light-like legs',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_color_num-field_lop_mass_scale_num'.
  $field_instances['field_collection_item-field_lop_color_num-field_lop_mass_scale_num'] = array(
    'bundle' => 'field_lop_color_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_mass_scale_num',
    'label' => 'Number of internal mass scales',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_color_num-field_lop_massive_prop_num'.
  $field_instances['field_collection_item-field_lop_color_num-field_lop_massive_prop_num'] = array(
    'bundle' => 'field_lop_color_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_massive_prop_num',
    'label' => 'Number of massive propagators',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_color_num-field_lop_massless_prop_num'.
  $field_instances['field_collection_item-field_lop_color_num-field_lop_massless_prop_num'] = array(
    'bundle' => 'field_lop_color_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_massless_prop_num',
    'label' => 'Number of massless propagators',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_color_num-field_lop_off_shell_leg_number'.
  $field_instances['field_collection_item-field_lop_color_num-field_lop_off_shell_leg_number'] = array(
    'bundle' => 'field_lop_color_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_off_shell_leg_number',
    'label' => 'Number of off-shell legs',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_internal_stuff-field_lop_picture_path'.
  $field_instances['field_collection_item-field_lop_internal_stuff-field_lop_picture_path'] = array(
    'bundle' => 'field_lop_internal_stuff',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the Path of the neato-generated picture.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_picture_path',
    'label' => 'Picture Path',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_legs_virt-field_lop_ext_legs_no'.
  $field_instances['field_collection_item-field_lop_legs_virt-field_lop_ext_legs_no'] = array(
    'bundle' => 'field_lop_legs_virt',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_ext_legs_no',
    'label' => 'Leg',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_legs_virt-field_lop_ext_legs_virt'.
  $field_instances['field_collection_item-field_lop_legs_virt-field_lop_ext_legs_virt'] = array(
    'bundle' => 'field_lop_legs_virt',
    'default_value' => array(
      0 => array(
        'value' => 'light-like',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_ext_legs_virt',
    'label' => 'Virtuality',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_props-field_lop_prop_mass'.
  $field_instances['field_collection_item-field_lop_props-field_lop_prop_mass'] = array(
    'bundle' => 'field_lop_props',
    'default_value' => array(
      0 => array(
        'value' => 'massless',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_prop_mass',
    'label' => 'Mass',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_props-field_lop_prop_nr'.
  $field_instances['field_collection_item-field_lop_props-field_lop_prop_nr'] = array(
    'bundle' => 'field_lop_props',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_prop_nr',
    'label' => 'P',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_props-field_lop_prop_power'.
  $field_instances['field_collection_item-field_lop_props-field_lop_prop_power'] = array(
    'bundle' => 'field_lop_props',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_prop_power',
    'label' => 'Power',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_topo_num-field_lop_leg_number'.
  $field_instances['field_collection_item-field_lop_topo_num-field_lop_leg_number'] = array(
    'bundle' => 'field_lop_topo_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_leg_number',
    'label' => 'Number of legs',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_topo_num-field_lop_loop_number'.
  $field_instances['field_collection_item-field_lop_topo_num-field_lop_loop_number'] = array(
    'bundle' => 'field_lop_topo_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_loop_number',
    'label' => 'Number of loops',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_topo_num-field_lop_nickel'.
  $field_instances['field_collection_item-field_lop_topo_num-field_lop_nickel'] = array(
    'bundle' => 'field_lop_topo_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_nickel',
    'label' => 'Nickel Index',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_topo_num-field_lop_prop_num'.
  $field_instances['field_collection_item-field_lop_topo_num-field_lop_prop_num'] = array(
    'bundle' => 'field_lop_topo_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_prop_num',
    'label' => 'Number of propagators',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_lop_topo_num-field_lop_vertex_number'.
  $field_instances['field_collection_item-field_lop_topo_num-field_lop_vertex_number'] = array(
    'bundle' => 'field_lop_topo_num',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_lop_vertex_number',
    'label' => 'Number of vertices',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-lop_integral-field_lop_color_num'.
  $field_instances['node-lop_integral-field_lop_color_num'] = array(
    'bundle' => 'lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 1,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lop_color_num',
    'label' => 'Coloring Numbers',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-lop_integral-field_lop_input'.
  $field_instances['node-lop_integral-field_lop_input'] = array(
    'bundle' => 'lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Graph Identifier, e.g. Adjacency List or Nickel Index',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lop_input',
    'label' => 'Graph Identifier',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 80,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-lop_integral-field_lop_internal_stuff'.
  $field_instances['node-lop_integral-field_lop_internal_stuff'] = array(
    'bundle' => 'lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field collection should not be visible. It stores internal stuff, that is not meant to be displayed directly to the user.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lop_internal_stuff',
    'label' => 'Internal Stuff',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-lop_integral-field_lop_legs_virt'.
  $field_instances['node-lop_integral-field_lop_legs_virt'] = array(
    'bundle' => 'lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choose the virtuality of the external legs. The choices are:
<ul>
<li>light-like : p^2 = 0</li>
<li>on_internal_mass_shell : p^2 &ne; 0. But p is on a mass shell of one of the (internal) propagators: p^2 = m_j.</li>
<li>off-shell: p is not light like and also not on one of the internal mass shells.</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 1,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lop_legs_virt',
    'label' => 'Legs Virtuality',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-lop_integral-field_lop_props'.
  $field_instances['node-lop_integral-field_lop_props'] = array(
    'bundle' => 'lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lop_props',
    'label' => 'Propagators',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-lop_integral-field_lop_topo_num'.
  $field_instances['node-lop_integral-field_lop_topo_num'] = array(
    'bundle' => 'lop_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the help text for this thing.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 1,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lop_topo_num',
    'label' => 'Topological Integral Numbers',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Choose the virtuality of the external legs. The choices are:
<ul>
<li>light-like : p^2 = 0</li>
<li>on_internal_mass_shell : p^2 &ne; 0. But p is on a mass shell of one of the (internal) propagators: p^2 = m_j.</li>
<li>off-shell: p is not light like and also not on one of the internal mass shells.</li>
</ul>');
  t('Coloring Numbers');
  t('Comment');
  t('Comment unused');
  t('Graph Identifier');
  t('Graph Identifier, e.g. Adjacency List or Nickel Index');
  t('Here you can provide further Publication details. Like journal publications.');
  t('Here, you can write comments that are not in your file. This is the place to specify details of your result or clarify important points.');
  t('Internal Stuff');
  t('Leg');
  t('Legs Virtuality');
  t('Mass');
  t('Nickel Index');
  t('Number of internal mass scales');
  t('Number of legs');
  t('Number of legs on an internal mass shell');
  t('Number of light-like legs');
  t('Number of loops');
  t('Number of massive propagators');
  t('Number of massless propagators');
  t('Number of off-shell legs');
  t('Number of propagators');
  t('Number of vertices');
  t('P');
  t('Picture Path');
  t('Please upload a file. It can be a text file, a Mathematca file or any other file that stores the Result in a useful way.');
  t('Power');
  t('Propagators');
  t('Publication');
  t('Result File');
  t('This field collection should not be visible. It stores internal stuff, that is not meant to be displayed directly to the user.');
  t('This field is required by the Comment module. But we are not using it. This is why it is removed from the submit form in nickelplay_form_comment_node_lop_integral_form_alter(). See https://www.drupal.org/node/1038652

And for some crazy reason, this field has to be required. So we set a default value that will be saved as a dummy value.');
  t('This is the Path of the neato-generated picture.');
  t('This is the help text for this thing.');
  t('Topological Integral Numbers');
  t('Virtuality');
  t('arXiv Identifier');

  return $field_instances;
}
