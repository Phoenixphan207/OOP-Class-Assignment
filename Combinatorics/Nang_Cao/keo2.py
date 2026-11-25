MOD = 10**9 + 7

n, k = map(int, input().split())

N = n - 1
R = k - 1

fact = [1] * (N + 1)
for i in range(1, N + 1):
    fact[i] = fact[i - 1] * i % MOD

ans = fact[N]
ans = ans * pow(fact[R], MOD - 2, MOD) % MOD
ans = ans * pow(fact[N - R], MOD - 2, MOD) % MOD

print(ans)