#! /usr/bin/python
#
# This script runs neato to draw a graph of a give Nickel Index
#
# Output:
#   File with neato (dot) language
#   SVG file that neato generates from previous file
#
# Get help by running this script with --help
# Usage example:
#   ./neato_from_nickel.py --nickel 'e11|e|' --output testfile
#   Expected output files: testfile, testfile.svg


import sys

import mygslib

# Set up argument parser
import argparse
parser = argparse.ArgumentParser(description='Draw neato image from Nickel Index')
parser.add_argument('--nickel', help='The Nickel index (you probably have to put it in quotation marks)')
parser.add_argument('--props', nargs='*', help='The "colors" of propagators. Viable options: "massless", "massive"')
parser.add_argument('--legs', nargs='*', help='the "colors" of legs. Viable options: "light-like", "int-mass", "offshell"')
parser.add_argument('--output', help='Filename of output picture')

# Print help message if no arguments are given
if len(sys.argv)==1:
    parser.print_help()
    sys.exit(1)

# Parse given arguments into args object
args = parser.parse_args()

# Produce GraphState object
gs = mygslib.graph_state.GraphState.from_str(args.nickel)

# Call function that draws diagram
mygslib.neatodraw(gs, args.output, args.props, args.legs)
