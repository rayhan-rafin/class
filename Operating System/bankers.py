
P = 5
R = 3

def calculateNeed(need, maxm, allot):
	for i in range(P):
		for j in range(R):
			need[i][j] = maxm[i][j] - allot[i][j] 


def isSafe(processes, avail, maxm, allot):
	need = []
	for i in range(P):
		l = []
		for j in range(R):
			l.append(0)
		need.append(l)
		
	
	calculateNeed(need, maxm, allot)

	
	finish = [0] * P                        # Mark all processes as infinish 
	
	safeSeq = [0] * P 

	
	work = [0] * R                         
	for i in range(R):
		work[i] = avail[i] 

	count = 0
	while (count < P):
		found = False
		for p in range(P): 

			if (finish[p] == 0): 
				for j in range(R):
					if (need[p][j] > work[j]):
						break
					
				if (j == R - 1):                        # If all needs of p were satisfied. 
					for k in range(R): 
						work[k] += allot[p][k] 

					safeSeq[count] = p
					count += 1

					finish[p] = 1
					found = True
		if (found == False):
			print("System is not in safe state")
			return False
            
	print("System is in safe state.",
			"\nSafe sequence is: ", end = " ")
	print(*safeSeq) 

	return True

if __name__ == "__main__":
    processes = [0, 1, 2, 3, 4]
    total = [10, 5, 7]  

    maxm = [[7, 5, 3], [3, 2, 2],
            [9, 0, 2], [2, 2, 2],
            [4, 3, 3]]
            
    allot = [[0, 1, 0], [2, 0, 0],
             [3, 0, 2], [2, 1, 1],
             [0, 0, 2]]

    avail = [total[i] - sum(allot[j][i] for j in range(len(processes))) for i in range(len(total))]

    print("The available resources are:", avail)
    
    isSafe(processes, avail, maxm, allot) 


