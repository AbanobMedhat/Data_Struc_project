import matplotlib.pyplot as plt
import networkx as nx

f = open("NAME.txt","r")
s = f.readline()
x1 = s.split(" ")[0]
x2 = s.split(" ")[1]
G = nx.DiGraph()

for x in f:
    First_node = x.split(" ")[0]
    Second_node = x.split(" ")[1]
    G.add_edges_from([(First_node,Second_node)])

color_map=[]

read_file = open("yes.txt","r")
re = read_file.read()
print(re)

for node in G:
    if node in re:
        color_map.append('red')
    else: color_map.append('blue')
pos = nx.spring_layout(G)
nx.draw_networkx_nodes(G, pos, cmap=plt.get_cmap('jet'),node_color=color_map,node_size = 500)
nx.draw_networkx_labels(G, pos)
nx.draw_networkx_edges(G, pos, arrows=False)
plt.show()
