import math
m, n, c = [int(x) for x in input().split()]

def nKm(n , m):
    return math.comb(n + m - 1 , n)

k = n // (c+1)
ket_qua = 0
for i in range(0 , k + 1):
    ket_qua += nKm(n - i*(c+1) , m) * math.comb(m ,i) * (-1)**i

print(ket_qua)
