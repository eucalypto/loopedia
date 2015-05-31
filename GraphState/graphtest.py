#! /usr/bin/python
# This script uses Python 2.7

import graph_state
import sys







simpleconfig = graph_state.PropertiesConfig.create()


print "Lets analyze the 1PI three bubbles -OOO- :"
onepi_raw = [(-1, 1), (1, 2), (1, 2), (2, 3), (2, 3), (3, 4), (3, 4), (4, -1)]
onepi_edges = map(simpleconfig.new_edge, onepi_raw)
onepi_gs = simpleconfig.new_graph_state(onepi_edges)

print "The Nickel Index is:", onepi_gs
print "The generated edge list is:", onepi_gs.edges

print "Irreducible?:", graph_state.operations_lib.is_1_irreducible(onepi_gs)
print "Vertex irreducible?:", graph_state.operations_lib.is_vertex_irreducible(onepi_gs)

print

print "Now let's analyze the 1 particle reducible two bubbles -O-O- :"

onepr_raw = [(-1, 1), (1, 2), (1, 2), (2, 3), (3, 4), (3, 4), (4, -1)]
onepr_edges = map(simpleconfig.new_edge, onepr_raw)
onepr_gs = simpleconfig.new_graph_state(onepr_edges)

print "The Nickel Index is:", onepr_gs
print "The generated edge list is:", onepr_gs.edges

print "Irreducible?:", graph_state.operations_lib.is_1_irreducible(onepr_gs)
print "Vertex irreducible?:", graph_state.operations_lib.is_vertex_irreducible(onepr_gs)

print

# print "Now what happens for disconnected graphs?:"
# import colored_edge_list_to_nickel
# colored_edge_list_to_nickel.main("[(-1, 1), (1, 2), (1, 2), (2, -1), (-1, 3), (3, 4), (3, 4), (4, -1)]")

print "Now let's analyze a non-planar diagram:"

nonplanar_raw = [(-1, 1), (1, 2), (1, 3), (1, 4), (-1, 2), (2, 3), (2, 4), (3, -1), (3, 4), (4, -1)]
nonplanar_edges = map(simpleconfig.new_edge, nonplanar_raw)
nonplanar_gs = simpleconfig.new_graph_state(nonplanar_edges)

print nonplanar_gs
print "edge list:", nonplanar_gs.edges
print "Irreducible: ", graph_state.operations_lib.is_1_irreducible(nonplanar_gs)
print "Vertex irreducible: ", graph_state.operations_lib.is_vertex_irreducible(nonplanar_gs)
