#!/usr/bin/python
#
# Script prints adjacency list of graph by given Nickel index. 
# Example:
#   $ python adjacency_list.py "e11|e|"
# Expected output:
#   (((0,), ), ((0, 1), ), ((0, 1), ), ((1,), ))

import sys
sys.path.insert(0,
  '/home/pcl247e/papara/Documents/mycode/GraphState-1.0.6/nickel')
sys.path.insert(0,
  '/home/pcl247e/papara/Documents/mycode/GraphState-1.0.6/graph_state')
import graph_state
import graph_state_property
import property_lib


nickel_raw = sys.argv[1]

gs = graph_state.GraphState.from_str(nickel_raw)

nickel_min = str(gs)
if nickel_raw <> nickel_min:
    raise ValueError("Non mininal nickel index %s, minimal = %s" %
                     (nickel_raw, nickel_min))

print gs.edges



