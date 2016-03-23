<?php

/**
 * @file
 * Contains helper function definitions
 */


/**
 * Returns an empty array
 *
 * This is used here to hide fields by setting '#pre_render' to this
 * function.
 */
function loopedia_empty_array()
{
  return array();
}


/**
 * Convert Adjacency list into graphstate format
 *
 * @param string $adjalist
 *   String $adjalist like '[[1, 2], [-3, 2], [1, -1]]'
 * @return string
 *   Return string with '-N' replaced by '-1'
 *   like '[[1, 2], [-1, 2], [1, -1]]'
 */
function loopedia_adjalist_to_graphstate($adjalist)
{
  $adjalist_gs = preg_replace('@(-[0-9]+)@', '-1', $adjalist);
  return $adjalist_gs;
}
