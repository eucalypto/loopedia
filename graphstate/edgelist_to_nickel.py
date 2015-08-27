#!/usr/bin/python
#
# Script prints Nickel Index from given adjacency list
# For example:
#   $ python edgelist_to_nickel.py "[[-1, 0], [0, 1], [0, 2], [1, 2], [1, 3], [2, 3], [3, -1]]"
# Expected output:
#   e12|23|3|e|


import sys
import graph_state
import ast

simpleconfig = graph_state.PropertiesConfig.create()

# read the argument string into variable:
adjalist_raw = sys.argv[1]

# Evaluate string to list of lists (in a hopefully safe way):
# https://docs.python.org/2/library/ast.html
adjalist = ast.literal_eval(adjalist_raw)

# Take steps to generate graph_state object:
adjalist_edges = map(simpleconfig.new_edge, adjalist)
adjalist_gs = simpleconfig.new_graph_state(adjalist_edges)

# print out Nickel index
print adjalist_gs
