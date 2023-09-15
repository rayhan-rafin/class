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

def dfs(graph, start):    #initializing needed list and set
    visited = set()  
    stack = []       
    stack.append(start)

    while stack:               #if theres anything in stack put in node
        node = stack.pop()      # pop queue
        if node not in visited:
            print(node)         
            visited.add(node)   # add to visited if not visited already

            
            for neighbor in reversed(graph[node]):  #traverse values of a key in reverse order
                if neighbor not in visited:         # reverse bcz we search from left
                    stack.append(neighbor)

dfs(graph, "tolarbagh")
