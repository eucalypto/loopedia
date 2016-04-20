<?php
/**
 * @file
 * loopedia_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function loopedia_feature_node_info() {
  $items = array(
    'lop_integral' => array(
      'name' => t('Integral'),
      'base' => 'node_content',
      'description' => t('This is the content type for the (Master) Integrals.'),
      'has_title' => '1',
      'title_label' => t('Title of Integral'),
      'help' => t('Explanation or submission guidelines, please.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
