#!/usr/bin/python
#
# Script prints adjacency list of graph by given Nickel index. 
# Example:
#   $ python adjacency_list.py "e11|e|"
# Expected output:
#   (((0,), ), ((0, 1), ), ((0, 1), ), ((1,), ))

import sys
import graph_state


name = sys.argv[1]

edge_property_key = graph_state.PropertyKey(name="color", is_edge_property=True, is_directed=False, externalizer=graph_state.PropertyExternalizer())

colored_edges_config = graph_state.PropertiesConfig.create(edge_property_key)

gs = colored_edges_config.graph_state_from_str(name)
nickel_ = str(gs)

if name <> nickel_:
    raise ValueError, "Non mininal nickel index %s, minimal = %s" % (name, nickel_)
    
print gs.edges
