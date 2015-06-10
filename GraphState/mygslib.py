
import sys
sys.path.insert(0,
  '/home/pcl247e/papara/Documents/mycode/GraphState-1.0.6/nickel')
sys.path.insert(0,
  '/home/pcl247e/papara/Documents/mycode/GraphState-1.0.6/graph_state')
import graph_state
import graph_state_property
import property_lib


def neatodraw(gs_object, filename):
    # My Python tip: with is used here to close the file properly,
    # even if an exception is thrown
    with open(filename, "w") as dotfile:
        dotfile.write("graph 1 {\n")
        dotfile.write("node [shape=point];\n")
        dotfile.write("V1 -- V2;\n")
        dotfile.write("V1 -- V2;\n")
        dotfile.write("}\n")
    
        
    from subprocess import call
    call(["neato", "-Tpdf", "-Gstart=2", "-Gepsilon=0.0001", "-O", filename])

