#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
class SoNguyenLon{
private: 
    static SoNguyenLon* ds[100];
    static int sl;

    char val[1000];

public:
    SoNguyenLon();
    ~SoNguyenLon();
    SoNguyenLon(const char* s);
    SoNguyenLon(int d, int n);

    void In(std::ostream & os);

    SoNguyenLon Cong(long long num);
    SoNguyenLon Tru(const SoNguyenLon& a);

    static SoNguyenLon SNLMax();
    static SoNguyenLon HieuVoiHangSo(long long a, const SoNguyenLon& b);


};