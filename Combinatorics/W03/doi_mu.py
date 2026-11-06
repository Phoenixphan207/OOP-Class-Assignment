MOD = 10**9 + 7
n = int(input())

if n < 2:
    print(0)
elif n == 2:
    print(1)
else:
    prev2 = 0  # f(1)
    prev1 = 1  # f(2)
    curr = 0

    for i in range(3, n + 1):
        curr = (i - 1) * (prev1 + prev2) % MOD
        prev2 = prev1
        prev1 = curr

    print(curr)