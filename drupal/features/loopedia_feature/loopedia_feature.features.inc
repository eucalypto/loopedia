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
      'help' => t('Please specify your Integral by providing a graph identifier (Adjacency List, Nickel Index) and selecting the properties of propagators and legs.<br>
After saving these general properties, you can add your reference and result. Just use the link "Add reference" on the page of the integral.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function loopedia_feature_default_search_api_index() {
  $items = array();
  $items['integral_index'] = entity_import('search_api_index', '{
    "name" : "Integral index",
    "machine_name" : "integral_index",
    "description" : "This is the index for the Integrals",
    "server" : "loopedia_solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "lop_integral" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "comments:field_comment_arxiv" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "comments:field_comment_comment" : { "type" : "list\\u003Ctext\\u003E" },
        "comments:field_comment_publication" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lop_color_num:field_lop_int_mass_shell_leg_num" : { "type" : "integer" },
        "field_lop_color_num:field_lop_light_like_leg_number" : { "type" : "integer" },
        "field_lop_color_num:field_lop_mass_scale_num" : { "type" : "integer" },
        "field_lop_color_num:field_lop_massive_prop_num" : { "type" : "integer" },
        "field_lop_color_num:field_lop_massless_prop_num" : { "type" : "integer" },
        "field_lop_color_num:field_lop_off_shell_leg_number" : { "type" : "integer" },
        "field_lop_input" : { "type" : "text" },
        "field_lop_topo_num:field_lop_ext_legs_no" : { "type" : "integer" },
        "field_lop_topo_num:field_lop_leg_number" : { "type" : "integer" },
        "field_lop_topo_num:field_lop_loop_number" : { "type" : "integer" },
        "field_lop_topo_num:field_lop_nickel" : { "type" : "text" },
        "field_lop_topo_num:field_lop_prop_num" : { "type" : "integer" },
        "field_lop_topo_num:field_lop_vertex_number" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-46", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_lop_input" : true,
              "comments:field_comment_arxiv" : true,
              "comments:field_comment_publication" : true,
              "comments:field_comment_comment" : true,
              "field_lop_topo_num:field_lop_nickel" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_lop_input" : true,
              "comments:field_comment_arxiv" : true,
              "comments:field_comment_publication" : true,
              "comments:field_comment_comment" : true,
              "field_lop_topo_num:field_lop_nickel" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_lop_input" : true,
              "comments:field_comment_arxiv" : true,
              "comments:field_comment_publication" : true,
              "comments:field_comment_comment" : true,
              "field_lop_topo_num:field_lop_nickel" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_lop_input" : true,
              "comments:field_comment_arxiv" : true,
              "comments:field_comment_publication" : true,
              "comments:field_comment_comment" : true,
              "field_lop_topo_num:field_lop_nickel" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function loopedia_feature_default_search_api_server() {
  $items = array();
  $items['loopedia_solr'] = entity_import('search_api_server', '{
    "name" : "Loopedia Solr",
    "machine_name" : "loopedia_solr",
    "description" : "This server manages the search indexing for Loopedia",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/drupal",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
