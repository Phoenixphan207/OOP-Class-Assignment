MOD = 10**9 + 7

n, k, L, H = map(int, input().split())

N = n - k * L
M = H - L + 1

MAX = N + k

fac = [1] * (MAX + 1)
for i in range(1, MAX + 1):
    fac[i] = fac[i - 1] * i % MOD

invfac = [1] * (MAX + 1)
invfac[MAX] = pow(fac[MAX], MOD - 2, MOD)

for i in range(MAX, 0, -1):
    invfac[i - 1] = invfac[i] * i % MOD


def C(n, r):
    return fac[n] * invfac[r] % MOD * invfac[n - r] % MOD


ans = 0

for i in range(min(k, N // M) + 1):
    term = C(k, i) * C(N - i * M + k - 1, k - 1) % MOD

    if i & 1:
        ans -= term
    else:
        ans += term

print(ans % MOD)