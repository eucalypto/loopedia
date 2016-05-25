<?php
/**
 * @file
 * loopedia_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function loopedia_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_add-integral:node/add/lop-integral.
  $menu_links['navigation_add-integral:node/add/lop-integral'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/lop-integral',
    'router_path' => 'node/add/lop-integral',
    'link_title' => 'Add Integral',
    'options' => array(
      'attributes' => array(
        'title' => 'This is the content type for the (Master) Integrals.',
      ),
      'identifier' => 'navigation_add-integral:node/add/lop-integral',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Integral');

  return $menu_links;
}
