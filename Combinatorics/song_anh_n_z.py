q = int(input())
for _ in range(q):
    t, n = map(int, input().split())

    ket_qua = 0
    if (t == 1): 
        if n % 2 == 0:
            ket_qua = n // 2
        else:
            ket_qua = (-(n+1) // 2)
    else :
        d1 =  n * 2
        d2 = -2 * n - 1
        if (d1 >= 0):
            ket_qua = (d1)
        else:
            ket_qua = (d2)


    print(ket_qua)

            