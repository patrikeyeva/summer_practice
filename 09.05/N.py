a, b = input().split()
a = int(a)
b = int(b)

if a == 1:
    print(10 ** b - 10 ** (a - 1) + 1)
else:
    print(10 ** b - 10 ** (a - 1))