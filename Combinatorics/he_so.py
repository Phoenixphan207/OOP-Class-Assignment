import math
n, k, a, b = map(int, input().split())

ket_qua = 0
if k > n: 
    ket_qua = 0
else: 
    ket_qua = math.comb(n , k) * (a ** (n-k)) * (b**k)

print(ket_qua)