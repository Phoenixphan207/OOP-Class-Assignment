#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

class HocSinh {
private:
    std::string name;
    float a ,b ,c;
    float dtb;
    int ms;

    static HocSinh* ds[100];
    static int sl;
    static int mssv;

public:
    HocSinh();
    HocSinh(const std::string& s, float d1, float d2, float d3);

    void DatHoTen(const std::string& s);
    void GanDiem(float d1, float d2, float d3);
    void GanGiaTri();

    static HocSinh HSDiemTBCaoNhat();
    void In(std::ostream& os);

    ~HocSinh();
};



