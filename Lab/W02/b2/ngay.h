#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class Ngay{
private: 
    int _ng, _th, _n;
    static const int arrNgayCuaThang[2][13];
    static bool LaNamNhuan(int n);

public: 
    Ngay();
    explicit Ngay(int n);
    ~Ngay();
    void Xuat(ostream& os) const;
};