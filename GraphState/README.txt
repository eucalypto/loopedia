Here I will collect my experience with GraphState.


*****************************************
2015-06-01

I found out that in the Graph State file "graph_state.py" there are
comments on the classes and modules. For instance it says that you
must not use the standard constructor to create graphstate objects
like graphs, edges and nodes. You have to use the class
graph_state.PropertiesConfig
graph_state.PropertiesConfig.create(property_keys)
graph_state.PropertiesConfig.new_node(property_keys)
graph_state.PropertiesConfig.new_edge(property_keys)
graph_state.PropertiesConfig.graph_state_from_str(property_keys)
graph_state.PropertiesConfig.new_graph_state(property_keys)

You can print out all isomorphies of your graph with the "sortings"
method of a graph_state object. 


*****************************************
2015-05-31 
The GraphState library is hosted mainly on google code:
  https://code.google.com/p/rg-graph/

But there is also a GitHub repository for it:
  https://github.com/batya239/rg-graph

The commits on both repositories do not seem to be the same. The
google code repository seems to be updated more often. There you can
download the archive package of GraphState 1.0.6. I'm not sure if they
made some changes to the library or to other (testing) files. 

There is also an old (2013) presentation about GraphState:
https://prezi.com/hjimrroep7xd/generation-graphstate-object-from-string/

But I can't reproduce the results from this presentation.

I have yet to figure out how to process adjacency lists (edge lists)
with colored edges. I can create a graph_state object out of an
extendet nickel index. But not out of an edge list with colored
edges. Or at least I don't know how to use it.
