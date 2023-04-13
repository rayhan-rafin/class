list = []
n = int(input("Number of elements: "))
for i in range(n):
    x = int(input("Enter element: "))
    list.append(x)
lrg = list[0]
sml = list[0]
for i in list:
    if (i > lrg):
        lrg = i
    if (i < sml):
        sml = i
print("Largest: ", lrg)
print("Smallest: ", sml)
