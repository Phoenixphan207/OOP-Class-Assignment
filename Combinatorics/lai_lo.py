n = int(input())
ten = input().split()
tien = list(map(int, input().split()))

cua_hang = []
for i in range(n):
    cua_hang.append((ten[i], tien[i]))

cua_hang.sort(key=lambda x: x[1], reverse=True)

for i in range(n):
    print(i + 1, cua_hang[i][0], cua_hang[i][1])