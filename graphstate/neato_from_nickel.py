#! /usr/bin/python
#
# This script runs neato to draw a graph of a give Nickel Index
#
# Input:
#   Argument 1: (string) Nickel Index
#   Argument 2: (string) Output file name
# Output:
#   File with neato (dot) language
#   SVG file that neato generates from previous file
#
# Usage example:
#   ./neato_from_nickel.py 'e11|e|' 'testfile.dot'
#   Expected output files: testfile.dot, testfile.dot.svg


import sys

import mygslib

# filename = "testfile.dot"
nickel = sys.argv[1]
filename = sys.argv[2]
gs = mygslib.graph_state.GraphState.from_str(nickel)
mygslib.neatodraw(gs, filename)
