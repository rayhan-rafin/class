count = 0
z= 100
a=["rayhan","shibly"] 
for i in range  (100,1000,1):
    for j in range (z,1000,1):
        x=i*j
        m = str (x)
        if m not in a:
            a.append(m)
            n = m[::-1]
            if (m==n):
             count = count +1 
    z=z+1
print (count)
