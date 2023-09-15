graph = {
    "tolarbagh":["technical","mirpur_1"],
    "technical":["tolarbagh","gabtoli","shamoly"],
    "mirpur_1":["tolarbagh","mirpur_10"],
    "gabtoli": ["technical","savar"],
    "shamoly": ["technical","dhanmondi"],
    "mirpur_10": ["mirpur_1"],
    "savar":["gabtoli"],
    "dhanmondi":["shamoly"]
}
def bfs(graph, start):   #initializing needed list and set
    visited = set()        
    queue = []             
    queue.append(start)    

    while queue:                #if theres anything in queue put in node
        node = queue.pop(0)     # pop queue
        if node not in visited:
            print(node)         
            visited.add(node)   # add to visited if not visited already

           
            for neighbor in graph[node]:     #traverse values of a key
                if neighbor not in visited:
                    queue.append(neighbor)

#starting from tolarbagh
bfs(graph, "tolarbagh")
