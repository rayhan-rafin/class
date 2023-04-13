oddsum = 0
evensum = 0
primesum = 2
for i in range(1001):
    if (i % 2 == 0):
        evensum = evensum+i
    else:
        oddsum = oddsum+i
print("sum of odd numbers: ", oddsum)
print("sum of even numbers: ", evensum)

for i in range(3, 101, 2):
    m = 0
    for j in range(2, i):
        if (i % j == 0):
            m = 1
            break
    if (m == 0):
        primesum = primesum+i

print("sum of prime numbers:", primesum)
