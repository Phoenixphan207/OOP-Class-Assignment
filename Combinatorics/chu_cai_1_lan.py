s = input()

MAX_VAL = 1000
res = [0] * (MAX_VAL + 1)

for ss in s.split():
    for x in ss:
        d = ord(x)
        res[d] += 1

ket_qua = []

for i, val in enumerate(res):
    if val == 1:
        ket_qua.append(chr(i))  

if not ket_qua:
    print(-1)
else:
    print(*ket_qua)