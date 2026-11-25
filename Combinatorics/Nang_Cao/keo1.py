MOD = 10**9 + 7

n, k = map(int, input().split())

N = n + k - 1

fact = [1] * (N + 1)
for i in range(1, N + 1):
    fact[i] = fact[i - 1] * i % MOD

inv_fact = [1] * (N + 1)
inv_fact[N] = pow(fact[N], MOD - 2, MOD)

for i in range(N, 0, -1):
    inv_fact[i - 1] = inv_fact[i] * i % MOD

ans = fact[N] * inv_fact[n] % MOD * inv_fact[N - n] % MOD
print(ans)