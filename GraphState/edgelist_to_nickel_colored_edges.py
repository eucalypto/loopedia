#!/usr/bin/python
#
# Script creates GraphState object from given adjacency list
# For example: 
#   $ python from_adjlist.py "[[-1, 0], [0, 1], [0, 2], [1, 2], [1, 3], [2, 3], [3, -1]]"
# Expected output:
#   e12|23|3|e|

import graph_state
import sys


def main(arg1):
    edge_property_key = graph_state.PropertyKey(name="color", is_edge_property=True, is_directed=False, externalizer=graph_state.PropertyExternalizer())

    color_config = graph_state.PropertiesConfig.create(edge_property_key)




    # edges must be an array (?). So we need do process the input string
    # to get this array. Here eval() is used. CAUTION! This evaluates the
    # string as python code. VERY DANGEROUS! 
    edges = eval(arg1)

    graph_state_edges = map(color_config.new_edge, edges)

    diagram = color_config.new_graph_state(graph_state_edges)

    print(diagram)

    # adjlist = eval(sys.argv[1])
    # adjlist = map(lambda e: graph_state.Edge(e), adjlist)

    # print graph_state.GraphState(adjlist)


if __name__ == "__main__":
    main(sys.argv[1])
