n, k = map(int, input().split())

a = 0
b = 0
c = 0
d = 0

def giai_thua(n):
    if (n == 0): return 1

    res = 1
    for i in range(1, n+1):
        res *= i
    return res
def nAk(n , k):
    return giai_thua(n) // (giai_thua(n-k))
def nCk(n , k):
    return giai_thua(n) // (giai_thua(k) * (giai_thua(n-k)))

if (k == 0):
    a = b = c = d = 1

if (n >= k): 
    a = nAk(n , k)
    b = nCk(n , k)
    
else:
    a = 0
    b = 0
c = nCk(n + k - 1, k)
d = pow(n, k)

print(a ,b ,c ,d)