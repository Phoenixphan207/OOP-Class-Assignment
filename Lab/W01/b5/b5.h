#pragma once
#include <iostream>

using namespace std;

#define MAX_VAL 10000

class MangSoNguyen {
private:
    int a[MAX_VAL];
    int n;

    // Hàm bổ trợ kẹp số lượng phần tử trong khoảng hợp lệ [0, MAX_VAL]
    int ChuanHoa(int x);

public:
    MangSoNguyen();
    MangSoNguyen(int x);
    MangSoNguyen(const int arr[], int x);
    MangSoNguyen(const MangSoNguyen& x);

    void Xuat();
};