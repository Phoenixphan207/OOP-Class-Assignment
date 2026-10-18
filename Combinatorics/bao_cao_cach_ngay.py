n, r, k = map(int, input().split())
a = list(map(int, input().split()))

if r >= n:
    ket_qua = []
else:
    # 1. Lấy các phần tử từ chỉ số r đến hết mảng với bước nhảy k
    # 2. Dùng [::-1] để đảo ngược lại danh sách (ngày lớn nhất đứng đầu, r đứng cuối)
    ket_qua = a[r::k][::-1]

print(*ket_qua)