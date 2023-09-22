import networkx as nx
import matplotlib.pyplot as plt

# Create a graph represented as an adjacency list with edge costs
graph = {
    "tolarbagh":[["technical",10],["mirpur_1",10]],
    "technical":[["tolarbagh",10],["gabtoli",5],["shamoly",10]],
    "mirpur_1":[["tolarbagh",10],["mirpur_10",15]],
    "gabtoli": [["technical",5],["savar",30]],
    "shamoly": [["technical",10],["dhanmondi",15]],
    "mirpur_10": [["mirpur_1",15]],
    "savar":[["gabtoli",30]],
    "dhanmondi":[["shamoly",15]]
}
# Create a directed graph
G = nx.Graph()

# Add nodes and edges with weights to the graph
for node, neighbors in graph.items():
    for neighbor, weight in neighbors:
        G.add_edge(node, neighbor, weight=weight)
      
# Define positions for the nodes (optional)
#pos = nx.spring_layout(G)

# Define positions for the nodes
pos = {
    'tolarbagh': (1, 2),
    'technical': (0, 1),
    'mirpur_1': (2, 1),
    'gabtoli': (1, 0),
    'shamoly': (0, -1),
    'mirpur_10': (3, 1),
    'savar': (2, 0),
    'dhanmondi': (-1, -1)
}
# Get edge weights as a dictionary
edge_labels = {(node, neighbor): weight['weight'] for node, neighbor, weight in G.edges(data=True)}

# Draw the graph
nx.draw(G, pos, with_labels=True, node_size=500, node_color='lightblue', font_size=10, font_color='black')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=8)


# Show the graph
plt.axis('off')
plt.show()
