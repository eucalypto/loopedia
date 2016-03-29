
import sys
import ast
import graph_state
from graph_state import graph_state_property
from graph_state import property_lib






def neatodraw(gs_object, filename):
    # My Python tip: with is used here to close the file properly,
    # even if an exception is thrown
    with open(filename, "w") as dotfile:
        dotfile.write("graph 1 {\n")
        dotfile.write("node [shape=point];\n")


        externalcount = 1
        propagatorcount = 1
        external_dot_string = '{node [shape=plaintext label=""] '
        dot_edges_string = ""
        for edge in gs_object.edges:
            if edge.is_external():
                string = "E" + str(externalcount)
                string += " -- "
                string += str(edge.internal_node) + " [fontname=Arial, labelfloat=true, fontsize=8, taillabel=Leg_" + str(externalcount) + "];"
                dot_edges_string += string + "\n"
                external_dot_string += " E" + str(externalcount)
                externalcount += 1
            else:
                string = (str(edge.nodes[0]) + " -- " + str(edge.nodes[1]) +
                          " [fontname=Arial, labelfloat=true, fontsize=8, label=P" + str(propagatorcount) + "];")
                dot_edges_string += string + "\n"
                propagatorcount += 1

        external_dot_string += "}\n"
        dot_edges_string += "}\n"
        dotfile.write(external_dot_string)
        dotfile.write(dot_edges_string)
    from subprocess import call
    call(["neato", "-Tsvg", "-Gstart=rand", "-Gepsilon=0.000001",
          "-O", filename])


# Takes a string representing an adjacency list, converts it to the
# format of graphstate and returns it 
def adjalist_to_graphstate(adjalist_raw):
    # Evaluate string to list of lists (in a hopefully safe way):
    # https://docs.python.org/2/library/ast.html
    adjalist = ast.literal_eval(adjalist_raw)

    for i in range(len(adjalist)):
        for j in range(len(adjalist[i])):
            adjalist[i][j] = max(adjalist[i][j], -1)

    return adjalist
