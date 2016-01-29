#!/usr/bin/python

import sys

import mygslib



filename = "testfile.dot"
# nickel = sys.argv[0]
nickel = "e12|34|35|4|5|e|"
gs = mygslib.graph_state.GraphState.from_str(nickel)
mygslib.neatodraw(gs, "blablatest")
