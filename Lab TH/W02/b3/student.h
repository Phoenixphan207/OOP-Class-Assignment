#pragma once 
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>
using namespace std;

class HocSinh {
private: 
    static HocSinh ds[100];
    static int sl;

    static int mssv;
    std::string name;
    int ms;

    float d1;
    float d2;
    float d3;
    float dtb;
public: 
    HocSinh();
    HocSinh(const char* s, float a, float b, float c);

    void DatHoTen(const char* s);
    void GanDiem(float a, float b, float c);

    static HocSinh HSDiemTBCaoNhat();

    void In(std::ostream& os);
};
