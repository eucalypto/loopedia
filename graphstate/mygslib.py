
import sys
import graph_state
from graph_state import graph_state_property
from graph_state import property_lib






def neatodraw(gs_object, filename):
    # My Python tip: with is used here to close the file properly,
    # even if an exception is thrown
    with open(filename, "w") as dotfile:
        dotfile.write("graph 1 {\n")
        dotfile.write("node [shape=point];\n")

    
        externalcount = 0
        external_dot_string = '{node [shape=plaintext label=""] '
        dot_edges_string = ""
        for edge in gs_object.edges:
            if edge.is_external():
                string = "E" + str(externalcount)
                string += " -- "
                string += str(edge.internal_node) + ";"
                dot_edges_string += string + "\n"
                external_dot_string += " E" + str(externalcount)
                externalcount += 1
            else:
                string = (str(edge.nodes[0]) + " -- " + str(edge.nodes[1]) +
                          ";")
                dot_edges_string += string + "\n"

        external_dot_string += "}\n"
        dot_edges_string += "}\n"
        dotfile.write(external_dot_string)
        dotfile.write(dot_edges_string)
    from subprocess import call
    call(["neato", "-Tpdf", "-Gstart=rand", "-Gepsilon=0.000001",
          "-O", filename])

