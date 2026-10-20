n = int(input())

def f(n):
    if (n == 1): return 1
    if (n == 2): return 2

    f1 = 1
    f2 = 2
    for i in range(3,  n + 1):
        f_moi = f1 + f2 + i
        f1 = f2
        f2 = f_moi
    return f2

print(f(n))