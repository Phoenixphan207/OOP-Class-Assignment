n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

so1 = 0
so2 = 0
so3 = 0
so4 = 0

a_m = set()
b_m = set()

for i in a:
    a_m.add(i)
for i in b:
    b_m.add(i)


aUb = set()
for i in a:
    aUb.add(i)
for i in b:
    aUb.add(i)

so1 = len(aUb)

for i in a_m:
    for j in b_m:
        if (j == i):
            so2 += 1

so3 = len(a_m) - so2
if (so3 < 0): so3 = 0

inB = len(b_m) - so2

so4 = inB + so3



print(so1, so2, so3, so4)