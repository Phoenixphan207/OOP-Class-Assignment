t = int(input())
import math
for _ in range(t):
    n = int(input())

    res = 0
    print((6*n + 3 + (-1)**n) // 4)


#     for k in range(0, math.floor(n/2) + 1):
#         res += math.comb(n+1-2*k , n - 2*k)

#     res2 = 0
#     for k in range(0, math.floor((n-3) / 2) + 1):
#         if n >= 3:
#             res2 += math.comb(n - 3 + 1 - 2*k, n - 3 - 2* k)
#         else:
#             res2 += 0

#     ket_qua.append(res - res2)

# for i in ket_qua:
#     print(i)
    