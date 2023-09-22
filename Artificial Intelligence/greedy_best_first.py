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
def greedy_best_first_search(graph, start, goal, heuristic):
    priority_queue = [(heuristic[start], start)]  # Priority queue with (heuristic, node)
    visited = set()
    k=0                               #1
    while priority_queue:
        k=k+1                         #2
        print (k,".")
        priority_queue.sort()  # Sort the queue based on the heuristic (greedy)
        print ("p_queue :",priority_queue)             #3
        h, node = priority_queue.pop(0)
        print ("node : ",node)                        #4
        if node == goal:
            print(f"Found a path from {start} to {goal}")
            return
        if node in visited:
            continue
        visited.add(node)
        print ("visited : ",visited)                 #6
        for neighbor, _ in graph[node]:
            if neighbor not in visited:
                priority_queue.append((heuristic[neighbor], neighbor))
    print(f"No path found from {start} to {goal}")

# Start Greedy Best-First Search from 'tolarbagh' to 'dhanmondi' in the given graph
greedy_best_first_search(graph, 'tolarbagh', 'dhanmondi', heuristic)
