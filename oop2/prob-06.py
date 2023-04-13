def sum(a, b):
    sum = a+b
    print("Sum of", a, "and", b, "is", sum)


def sub(a, b):
    sub = a-b
    print("Sub of", a, "and", b, "is", sub)


def multi(a, b):
    multi = a*b
    print("Multi of", a, "and", b, "is", multi)


def div(a, b):
    div = a/b
    print("Div of", a, "and", b, "is", div)


def mod(a, b):
    mod = a % b
    print("Mod of", a, "and", b, "is", mod)


a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
sum(a, b)
sub(a, b)
multi(a, b)
div(a, b)
mod(a, b)
