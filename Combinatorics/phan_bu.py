m, k = map(int, input().split())
ca = list(map(int, input().split()))
L, R = map(int, input().split())

def count_days(X):
    if X <= 0:
        return 0
    
    full_cycles = X // m
    rem = X % m
    
    ans = full_cycles * k
    
    for j in ca:
        target_day = j if j != 0 else m
        if target_day <= rem:
            ans += 1
            
    return ans

on = count_days(R) - count_days(L - 1)
total_days = R - L + 1
off = total_days - on

print(f"{on} {off}")