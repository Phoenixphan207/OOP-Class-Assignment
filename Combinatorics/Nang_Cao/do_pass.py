s = input().strip()
MOD = 10**9 + 7
n = len(s)

fact = [1] * (n + 1)
for i in range(1, n + 1):
    fact[i] = (fact[i - 1] * i) % MOD
    
counts = {}
for ch in s:
    counts[ch] = counts.get(ch, 0) + 1
    
denominator = 1
for count in counts.values():
    if count > 1:
        denominator = (denominator * fact[count]) % MOD
        
ans = (fact[n] * pow(denominator, MOD - 2, MOD)) % MOD
print(ans)