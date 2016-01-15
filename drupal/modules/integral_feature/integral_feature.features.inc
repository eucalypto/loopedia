<?php
/**
 * @file
 * integral_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function integral_feature_node_info() {
  $items = array(
    'features_integral' => array(
      'name' => t('Features Integral'),
      'base' => 'node_content',
      'description' => t('This is the description of the Integral Content type, that I defined in the Drupal UI and exported with Features.'),
      'has_title' => '1',
      'title_label' => t('Title field label alpha'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
