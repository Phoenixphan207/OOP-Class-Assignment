#pragma once 

#include <iostream>
#include <string>

using namespace std;

class SoNguyenLon {
private:
    string val;
    static SoNguyenLon maxObj; 

    static void daoNguocChuoi(string& str);
    void normalize();
    static bool soNhanHon(const string& a, const string& b);
    void updateMax();

public:
    SoNguyenLon();
    SoNguyenLon(string s);

    SoNguyenLon(int d, int len);

    void In(ostream& os) const;

    static SoNguyenLon SNLMax();

    SoNguyenLon Cong(long long num) const;

    static SoNguyenLon HieuVoiHangSo(long long hangSo, const SoNguyenLon& snl);

    SoNguyenLon Tru(const SoNguyenLon& other) const;
};