import math
n, m = map(int, input().split())

ket_qua = 0
for k in range(m+1):
    ket_qua += math.comb(n,k) * ((-1) ** k)

print(ket_qua)