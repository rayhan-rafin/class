x = list(range(0, 11))
sum = 0

y = []
for i in x:
    y.append(pow(i, 3))
for i in y:
    sum = sum + i
print("list is:", y)
print("sum is:", sum)
