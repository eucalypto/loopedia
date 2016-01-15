<?php
/**
 * @file
 * integral_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function integral_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-features_integral-field_features_long_text'.
  $field_instances['node-features_integral-field_features_long_text'] = array(
    'bundle' => 'features_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Help textt',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'example_node_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_features_long_text',
    'label' => 'features long text',
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
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-features_integral-field_features_numbers'.
  $field_instances['node-features_integral-field_features_numbers'] = array(
    'bundle' => 'features_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the help text for Features numbers',
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
      'example_node_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_features_numbers',
    'label' => 'Features numbers',
    'required' => 1,
    'settings' => array(
      'max' => 2048,
      'min' => 10,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => -3,
    ),
  );

  // Exported field_instance:
  // 'node-features_integral-field_features_term_reference'.
  $field_instances['node-features_integral-field_features_term_reference'] = array(
    'bundle' => 'features_integral',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Help text',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'example_node_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_features_term_reference',
    'label' => 'features term reference',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-features_integral-field_features_text'.
  $field_instances['node-features_integral-field_features_text'] = array(
    'bundle' => 'features_integral',
    'default_value' => array(
      0 => array(
        'value' => 'default value',
      ),
    ),
    'deleted' => 0,
    'description' => 'This is the help text for the features text field',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'example_node_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_features_text',
    'label' => 'Features text',
    'required' => 1,
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
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Features numbers');
  t('Features text');
  t('Help text');
  t('Help textt');
  t('This is the help text for Features numbers');
  t('This is the help text for the features text field');
  t('features long text');
  t('features term reference');

  return $field_instances;
}
