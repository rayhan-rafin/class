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
def ucs(graph, start, goal):
    priority_queue = [(0, start)]  # Priority queue with (cost, node)
    visited = set()
    k=0                         #1
    while priority_queue:
        k=k+1                   #2
        print (k,".")
        priority_queue.sort()  # Sort the queue based on cost
        print ("p_queue :",priority_queue)             #3
        cost, node = priority_queue.pop(0)
        print ("node : ",node)                        #4
        print ("cost : ",cost)                        #5
        if node in visited:
            continue
        visited.add(node)
        print ("visited : ",visited)                 #6
        print()
        if node == goal:
            print(f"Found a path from {start} to {goal} with cost {cost}")
            return
        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                priority_queue.append((cost + edge_cost, neighbor))
        
    print(f"No path found from {start} to {goal}")

# Start UCS from 'tolarbagh' to 'dhanmondi' in the given graph
ucs(graph, 'tolarbagh', 'dhanmondi')
