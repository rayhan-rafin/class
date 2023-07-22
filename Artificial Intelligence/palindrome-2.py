count = 0
z= 100
a=[]  
for i in range  (100,1000,1):
    for j in range (z,1000,1):
        x=i*j
        m = str (x)
        n = m[::-1]
        if (m==n and m not in a ):
            a.append(m)
            count = count +1
    z=z+1
print (count)
