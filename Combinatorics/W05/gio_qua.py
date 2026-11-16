MOD = 10**9 + 7

k, N = map(int, input().split())

types = []
for _ in range(k):
    l, r, d = map(int, input().split())

    # bội đầu tiên của d trong [l, r]
    first = ((l + d - 1) // d) * d

    cnt = (r - first) // d + 1
    types.append((first, d, cnt))

dp = [0] * (N + 1)
dp[0] = 1

for first, d, cnt in types:
    shifted = [0] * (N + 1)

    # dịch bởi first
    for s in range(N - first + 1):
        shifted[s + first] = dp[s]

    ndp = [0] * (N + 1)

    for rem in range(d):
        window = 0
        q = []

        pos = rem
        while pos <= N:
            val = shifted[pos]

            window = (window + val) % MOD
            q.append(val)

            if len(q) > cnt:
                window = (window - q.pop(0)) % MOD

            ndp[pos] = window

            pos += d

    dp = ndp

print(dp[N] % MOD)