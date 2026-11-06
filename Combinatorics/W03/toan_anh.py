n, k = map(int, input().split())
import math
MOD = 10**9 + 7

d = 0
comb = 1  

for i in range(1, k + 1):
    comb = comb * (k - i + 1) * pow(i, MOD - 2, MOD) % MOD
    term = comb * pow(k - i, n, MOD) % MOD
    
    if i % 2 == 1:  
        d = (d + term) % MOD
    else:
        d = (d - term) % MOD

ans = (pow(k, n, MOD) - d) % MOD
print(ans)