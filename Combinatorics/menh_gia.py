import math
m, n, k = [int(x) for x in input().split()]
menh_gia = [int(x) for x in input().split()]


ket_qua = 0
if (k == 0):    

    ket_qua = math.comb(n + m - 1, n)
else:
    if (n < m): ket_qua = 0
    else:
        ket_qua = math.comb(n - 1, n - m)
print(ket_qua)