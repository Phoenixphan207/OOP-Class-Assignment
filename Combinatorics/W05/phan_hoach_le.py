MOD = 10**9 + 7

T = int(input())
queries = [int(input()) for _ in range(T)]

mx = max(queries)

dp = [0] * (mx + 1)
dp[0] = 1

for odd in range(1, mx + 1, 2):
    for s in range(odd, mx + 1):
        dp[s] = (dp[s] + dp[s - odd]) % MOD

for n in queries:
    print(dp[n])