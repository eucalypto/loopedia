#!/usr/bin/python

import sys

import mygslib



filename = "testfile.dot"
nickel = sys.argv[0]
gs = mygslib.graph_state.GraphState.from_str(nickel)
mygslib.neatodraw(gs, filename)
