#pragma once

#include <iostream>
using namespace std;

#define MAX_VAL 10000


class MangSoNguyen {
private:
    int a[MAX_VAL] = {0};
    int n;
public:
    MangSoNguyen();
    MangSoNguyen(int x);
    MangSoNguyen(int arr[] , int x);
    MangSoNguyen(const MangSoNguyen& x);

    void Xuat();
};