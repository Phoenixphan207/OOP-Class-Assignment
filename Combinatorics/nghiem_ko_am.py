import math
m, n = map(int, input().split())

ket_qua = math.comb(n + m , m)
print(ket_qua)