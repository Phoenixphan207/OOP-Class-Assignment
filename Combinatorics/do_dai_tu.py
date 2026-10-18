c = input().strip()
cac_tu = input().split()

ket_qua = []

for x in cac_tu:
    if c.lower() in x.lower():
        ket_qua.append(len(x))

if not ket_qua:
    print(-1)
else: 
    print(*ket_qua)