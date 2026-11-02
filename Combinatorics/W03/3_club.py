T = int(input())
ket_qua = []
for _ in range(T):
    n, a, b, c, p, q, r, s = map(int, input().split())

    if (s < 0 or p < s or q < s or r < s or
        p > a or p > b or
        q > b or q > c or
        r > a or r > c):
        ket_qua.append(-1)
        continue

    a1 = a - p - r + s
    b1 = b - p - q + s
    c1 = c - q - r + s
    if a1 < 0 or b1 < 0 or c1 < 0:
        ket_qua.append(-1)
        continue

    ans = a + b + c - p - q - r + s

    if ans > n:
        ket_qua.append(-1)
    else:
        ket_qua.append(n - ans)

for i in ket_qua:
    print(i)