d, x, k, r = map(int, input().split())

if r < 0 or r > d or (k - r) < 0 or (k - r) > x or k > (d + x):
    tu, mau = 0, 1
else:
    def giai_thua(n):
        if (n == 0): return 1

        res = 1
        for i in range(1,n+1):
            res *= i
        return res

    tu = giai_thua(d) * giai_thua(x) * giai_thua(k) * giai_thua(d + x - k)
    mau = giai_thua(r) * giai_thua(d-r) * giai_thua(k-r) * giai_thua(x-k+r) * giai_thua(d + x)

    def gcd(tu , mau):
        while (mau > 0):
            tmp = tu % mau
            tu = mau
            mau = tmp
        return tu


    g = gcd(tu, mau)
    tu //= g
    mau //= g
print(f"{tu}/{mau}")