n, k = map(int, input().split())
import math
d = 0
for i in range(1, k+1): 
    d += (-1) **(i+1) * math.comb(k,  i) * ((k-i)**n)

print((k**n - d)  % (10**9 + 7))
