n = int(input())

if (n == 0):
    print(1)

else:
    def giai_thua(n):
        res = 1
        for i in range(2, n+1):
            res *= i
        return res

    d = giai_thua(n)
    ket_qua = 0

    while (d > 0):
        d //= 10
        ket_qua += 1
    print(ket_qua)




