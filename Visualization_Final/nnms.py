# import matplotlib to be able to draw the graph
# import networkx as a lib important for graph operations

import matplotlib.pyplot as plt
import networkx as nx


f = open("NAME.txt","r")            # here I'm trying to open the file which has the data
s = f.readline()                    # I made those lines to read the first line in the file to get rid of it and keep reading from the next one
x1 = s.split(" ")[0]
x2 = s.split(" ")[1]
G = nx.Graph()

for x in f:                         # That loop is made to read the nodes and what they are connected to
    First_node = x.split(" ")[0]
    Second_node = x.split(" ")[1]

    # here I'm just adding nodes and connecting it to each other
    G.add_edges_from([(First_node,Second_node)])

color_map=[]                        # It's a variable made to select and contain colors in it for each node

degree = nx.degree_centrality(G)    # It's a variable made to calculate the degree centrality

Max_value = max(degree.values())    # It's a variable made to calculate the Max value in the algorithm

for node in G:                      # this loop is simply checking on nodes of the graph and checks if it has the Max centrality or not
    if node in degree:
        value = degree.get(node)
        if Max_value == value:
            color_map.append('red')
        else: color_map.append('blue')

pos = nx.spring_layout(G)
nx.draw_networkx_nodes(G, pos, cmap=plt.get_cmap('jet'),node_color=color_map,node_size = 500)
nx.draw_networkx_labels(G, pos)
nx.draw_networkx_edges(G, pos, arrows=False)
plt.show()
