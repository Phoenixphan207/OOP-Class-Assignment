m, n = map(int, input().split())
a = []
for _ in range(m):
    a.append(list(map(int, input().split())))
    
for j in range(n):
    gio_j = []
    for i in range(m):
        gio_j.append(a[i][j])
    print(*gio_j)

tong_theo_gio = []
for j in range(n):
    tong = 0
    for i in range(m):
        tong += a[i][j]
    tong_theo_gio.append(tong)

print(*tong_theo_gio)