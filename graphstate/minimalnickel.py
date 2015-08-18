#!/usr/bin/python
#
# Script takes nickel index and prints the minimal version of it
# Example:
#   $ python adjacency_list.py "e11|e|"
# Expected output:
#   "e11|e|"

import sys
import graph_state




nickel_raw = sys.argv[1]

gs = graph_state.GraphState.from_str(nickel_raw)

print str(gs)
