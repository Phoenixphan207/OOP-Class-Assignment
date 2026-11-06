n,m = map(int, input().split())
import math

if m > n or m == n - 1:
    print(0)
elif m == n:
    print(1)
else:
        
    k = n - m
    D = [0] * (k + 1)
    D[0] = 1
    D[1] = 0
    for i in range(2, k + 1):
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) 

    ans = (math.comb(n, m) * D[k])
    print(ans)