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



def main(nickel_raw):
    colored_edges_config = graph_state.PropertiesConfig.create(
                             graph_state_property.PropertyKey(
                               name="color", is_edge_property=True,
                               is_directed=False,
                               externalizer=property_lib.StringExternalizer()))

    gs_graph = colored_edges_config.graph_state_from_str(nickel_raw)



    nickel_ = str(gs_graph)
    if nickel_raw <> nickel_:
        raise ValueError("Non mininal nickel index %s, minimal = %s" %
                         (nickel_raw, nickel_))

    print gs_graph.edges




if __name__ == "__main__":
    main(sys.argv[1])
