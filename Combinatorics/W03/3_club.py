T = int(input())
ket_qua = []
for _ in range(T):
    n, a, b, c, p, q, r, s = map(int, input().split())

    p_only = p - s  
    q_only = q - s  
    r_only = r - s  

    a_only = a - p - q + s
    b_only = b - p - r + s
    c_only = c - q - r + s

    total_union = a + b + c - p - q - r + s

    if (s < 0 or p_only < 0 or q_only < 0 or r_only < 0 or 
        a_only < 0 or b_only < 0 or c_only < 0 or total_union > n):
        ket_qua.append(-1)
    else:
        ket_qua.append(n - total_union)
for i in ket_qua:
    print(i)