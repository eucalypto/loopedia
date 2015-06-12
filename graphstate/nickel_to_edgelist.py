#!/usr/bin/python
#
# Script prints adjacency list of graph by given Nickel index. 
# Example:
#   $ python adjacency_list.py "e11|e|"
# Expected output:
#   (((0,), ), ((0, 1), ), ((0, 1), ), ((1,), ))

import sys
import graph_state
from graph_state import graph_state_property
from graph_state import property_lib




nickel_raw = sys.argv[1]

gs = graph_state.GraphState.from_str(nickel_raw)

nickel_min = str(gs)
if nickel_raw <> nickel_min:
    raise ValueError("Non mininal nickel index %s, minimal = %s" %
                     (nickel_raw, nickel_min))

print gs.edges



