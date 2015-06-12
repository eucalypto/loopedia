#!/usr/bin/python
#
# Script creates GraphState object from given adjacency list
# For example: 
#   $ python from_adjlist.py "[[-1, 0], [0, 1], [0, 2], [1, 2], [1, 3], [2, 3], [3, -1]]"
# Expected output:
#   e12|23|3|e|


import sys
sys.path.insert(0,
  '/home/pcl247e/papara/Documents/mycode/GraphState-1.0.6/nickel')
sys.path.insert(0,
  '/home/pcl247e/papara/Documents/mycode/GraphState-1.0.6/graph_state')
import graph_state
import graph_state_property
import property_lib



def main(edgelist_raw, colorlist_raw):
    COLORS_CONFIG = graph_state.PropertiesConfig.create(
                        graph_state_property.PropertyKey(name="Gandalf",
                        is_edge_property=True, is_directed=False,
                        externalizer=property_lib.StringExternalizer()))


    # edgelist and colorlist have to be arrays. So we need do process
    # the input strings to get the arrays. Here eval() is
    # used. 
    # CAUTION! This evaluates the string as python code. VERY
    # DANGEROUS!
    edgelist = eval(edgelist_raw)
    colorlist = eval(colorlist_raw)

    if len(edgelist) != len(colorlist):
        raise ValueError("Number of edges does NOT correspond to "
                         "number of colorings")


    graph_state_edges = []
    for i in range(0, len(edgelist)):
        graph_state_edges.append(COLORS_CONFIG.new_edge(edgelist[i],
                                                        Gandalf=colorlist[i]))


    diagram = COLORS_CONFIG.new_graph_state(graph_state_edges)

    print(diagram)



if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
