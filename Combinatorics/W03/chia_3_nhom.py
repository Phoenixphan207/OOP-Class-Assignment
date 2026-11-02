import math

q = int(input())
ket_qua = []
for _ in range(q):
    n = int(input())

    ket_qua.append(3 ** n - 3 * (2**n) + 3)

for i in ket_qua:
    print(i)
