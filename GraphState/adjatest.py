#!/usr/bin/python
#
# Script prints adjacency list of graph by given Nickel index. 
# Example:
#   $ python adjacency_list.py "e11|e|"
# Expected output:
#   (((0,), ), ((0, 1), ), ((0, 1), ), ((1,), ))

import sys
import fileinput
import graph_state


for name_raw in fileinput.input():
    name = name_raw.strip()
    gs = graph_state.GraphState.from_str(name)
    nickel_ = str(gs)

    if name <> nickel_:
        raise ValueError, "Non mininal nickel index %s, minimal = %s" % (name, nickel_)
    
    print gs.edges
