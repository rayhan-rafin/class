x = input()
d = 0
a = 0
for i in x:
    if (i.isdigit()):
        d = d+1
    elif (i.isalpha()):
        a = a+1
print("Alphabet:", a)
print("Digit:", d)
