import math
q = int(input())
ket_qua = []
for _ in range(q):
    n = int(input())
    x = math.comb(2 * n , n)
    ket_qua.append(x % (10 ** 9 + 7))
for i in ket_qua:
    print(i)
