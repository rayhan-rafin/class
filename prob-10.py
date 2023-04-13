n = int(input())
a = 0
b = 1
c = 0
print(a)
print(b)
for i in range(n-2):
    print(a+b)
    c = a+b
    a = b
    b = c
