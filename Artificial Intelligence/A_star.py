# Create a graph represented as an adjacency list
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

# Heuristic function to estimate the distance to the goal ('dhanmondi' in this example)
heuristic = {
    'tolarbagh': 30,'technical': 20,'mirpur_1': 25,'gabtoli': 20,'shamoly': 15,'mirpur_10': 15,'savar': 5,'dhanmondi': 0
}
def a_star(graph, start, goal, heuristic):
    open_list = [(0, start)]  # Priority queue with (f-value, node)
    g_values = {node: float('inf') for node in graph}
    g_values[start] = 0
    visited = set()
    k=0                               #1
    while open_list:
        k=k+1                         #2
        print (k,".")                 #2.5
        open_list.sort()  # Sort the queue based on f-value
        print ("open_list :",open_list)             #3
        f, node = open_list.pop(0)
        print ("node : ",node)                        #4
        if node == goal:
            print(f"Found a path from {start} to {goal}")
            return
        if node in visited:
            continue
        visited.add(node)
        print ("visited : ",visited)                 #6
        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                tentative_g = g_values[node] + edge_cost
                if tentative_g < g_values[neighbor]:
                    g_values[neighbor] = tentative_g
                    f_value = tentative_g + heuristic[neighbor]
                    open_list.append((f_value, neighbor))
    print(f"No path found from {start} to {goal}")

# Start A* from 'tolarbagh' to 'dhanmondi' in the given graph
a_star(graph, 'tolarbagh', 'dhanmondi', heuristic)
