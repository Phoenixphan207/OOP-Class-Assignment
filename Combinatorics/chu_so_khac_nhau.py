import math

n, k = map(int, input().split())

if n > 10:
    print(0)

elif n == 1:
    print(sum(i % k == 0 for i in range(1, 10)))

else:
    p = math.factorial(8) // math.factorial(10 - n)

    m = sum(i % k == 0 for i in range(1, 10))

    print(p * (9 + 8 * m))