import math
m, n, c = [int(x) for x in input().split()]

d1 = math.comb(n+m-1 , n)

k = n // c 
d2 = 0
for i in range(1,k+1):
    d2 += math.comb(m, i) * math.comb(n - i*c + m - 1, n - i*c) * (-1)**i

print(d1 + d2)