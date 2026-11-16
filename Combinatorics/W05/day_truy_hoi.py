MOD = 10**9 + 7

a0, a1, p, q, Q = map(int, input().split())

a0 %= MOD
a1 %= MOD
p %= MOD
q %= MOD


def mat_mul(A, B):
    return [
        [
            (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD,
            (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD,
        ],
        [
            (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD,
            (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD,
        ],
    ]


def mat_pow(n):
    res = [[1, 0], [0, 1]]
    base = [[p, q], [1, 0]]

    while n:
        if n & 1:
            res = mat_mul(res, base)
        base = mat_mul(base, base)
        n >>= 1

    return res


def calc(n):
    if n == 0:
        return a0
    if n == 1:
        return a1

    M = mat_pow(n - 1)

    return (M[0][0] * a1 + M[0][1] * a0) % MOD


for _ in range(Q):
    n = int(input())
    print(calc(n))