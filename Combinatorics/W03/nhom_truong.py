n, k = map(int, input().split())
import math
if k ==  0 or k > n: 
    print(0)

else:
    print(math.comb(n,k) * k)