processes = ["p1", "p2", "p3", "p4"]
bt = [8, 4, 9, 5] 
at = [0, 1, 2, 3] 

n = len(processes)
rt = list(bt)
wt = [0] * n
complete = 0
t = 0
minm = float('inf')
short = 0
check = False

while complete != n:
    for j in range(n):
        if at[j] <= t and rt[j] < minm and rt[j] > 0:
            minm = rt[j]
            short = j
            check = True
    if not check:
        t += 1
        continue
    rt[short] -= 1
    minm = rt[short]
    if minm == 0:
        minm = float('inf')
    if rt[short] == 0:
        complete += 1
        check = False
        fint = t + 1
        wt[short] = fint - bt[short] - at[short]
        if wt[short] < 0:
            wt[short] = 0
    t += 1

avg_wt = sum(wt) / n
print("Average waiting time: ", avg_wt)
