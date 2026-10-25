import math
n, a = map(int, input().split())

d1 = n - a
if (d1 - 1 <= 0):
    print(0)
else:
    print(math.factorial(n-a) - math.factorial(n-a-1))

