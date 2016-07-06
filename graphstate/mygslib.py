
import sys
import ast
import graph_state
from graph_state import graph_state_property
from graph_state import property_lib





# Draw diagram of given nickel Index.
# Input:
#  - gs_obect: a GraphState obect for graph
#  - filename: string for output file name
#  - (optional) props: list of propagator "colors"
#  - (optional) legs: list of leg "colors"
# Output: NO return value! Writes graphviz dot file and processes it
# with neato.
def neatodraw(gs_object, filename, props=None, legs=None):
    # My Python tip: with is used here to close the file properly,
    # even if an exception is thrown
    with open(filename, "w") as dotfile:
        dotfile.write("graph 1 {\n")
        dotfile.write("node [shape=point];\n")

        # Convert colors to dot language
        if (props != None):
            props_dot = edge_color_to_graphviz(props)
        if (legs != None):
            legs_dot = edge_color_to_graphviz(legs)

        # Set up counts for legs and propagators
        externalcount = 1
        propagatorcount = 1
        external_dot_string = '{node [shape=plaintext label=""] '
        dot_edges_string = ""
        for edge in gs_object.edges:
            if edge.is_external():
                string = "E" + str(externalcount)
                string += " -- "
                string += str(edge.internal_node) + " [fontname=Arial, labelfloat=true, fontsize=8, taillabel=Leg_" + str(externalcount)
                if (props != None):
                    string += legs_dot[externalcount - 1]
                string += "];"
                dot_edges_string += string + "\n"
                external_dot_string += " E" + str(externalcount)
                externalcount += 1
            else:
                string = (str(edge.nodes[0]) + " -- " + str(edge.nodes[1]) +
                          " [fontname=Arial, labelfloat=true, fontsize=8, label=P" + str(propagatorcount))
                if (legs != None):
                    string += props_dot[propagatorcount - 1]
                string += "];"
                dot_edges_string += string + "\n"
                propagatorcount += 1

        external_dot_string += "}\n"
        dot_edges_string += "}\n"
        dotfile.write(external_dot_string)
        dotfile.write(dot_edges_string)
    from subprocess import call
    call(["neato", "-Tsvg", "-Gstart=rand", "-Gepsilon=0.000001",
          "-O", filename])


# Convert line "colors" to graphviz options (both strings)
#
# Input: list of strings characterizing the 'color' of a line
#
# Output: list of corresponding strings to attach to line description in
# graphviz file
def edge_color_to_graphviz(colors):
    ret = []
    for color in colors:
        if (color == 'massless'):
            ret.append(', color=gray')
        elif (color == 'massive'):
            ret.append(', penwidth=1')
        elif (color == 'light-like'):
            ret.append(', color=gray')
        elif (color == 'int-mass'):
            ret.append(', penwidth=1')
        elif (color == 'offshell'):
            ret.append(', penwidth=1.5')
    return ret



# Takes a string representing an adjacency list, converts it to the
# format of graphstate and returns it
def adjalist_to_graphstate(adjalist_raw):
    # Evaluate string to list of lists (in a hopefully safe way):
    # https://docs.python.org/2/library/ast.html
    adjalist = ast.literal_eval(adjalist_raw)

    # Convert external legs, represented by negative integers (-2, -14, ...),
    # to -1, because GraphState allows only "-1" for the external legs.
    for i in range(len(adjalist)):
        for j in range(len(adjalist[i])):
            adjalist[i][j] = max(adjalist[i][j], -1)

    return adjalist
