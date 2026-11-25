#include "r3.h"
using namespace std;

HocSinh* HocSinh::ds[100];
int HocSinh::sl = 0;
int HocSinh::mssv = 23120001;

void ChuanHoaDiem(float& a, float& b, float& c) {
    a = (a > 10) ? 10 : a;
    b = (b > 10) ? 10 : b;
    c = (c > 10) ? 10 : c;
    
    a = (a < 0) ? 0 : a;
    b = (b < 0) ? 0 : b;
    c = (c < 0) ? 0 : c;
}
HocSinh::HocSinh() {
    name = "";
    a = b = c = dtb = 0.0;

    ms = mssv;
    mssv ++;

    ds[sl++] = this;
}

HocSinh::HocSinh(const string &s , float d1, float d2, float d3) {
    ChuanHoaDiem(d1, d2, d3);

    name = s;
    a = d1;
    b = d2;
    c = d3;

    dtb = (d1+d2+d3) / 3;
    ms = mssv;
    
    ds[sl++] = this;
    mssv += 1;
}

void HocSinh::DatHoTen(const string &s) {
    this->name = s;

}

void HocSinh::GanDiem(float d1, float d2, float d3) {
    ChuanHoaDiem(d1, d2, d3);

    a = d1;
    b = d2;
    c = d3;
    dtb = (d1 + d2 + d3) / 3;


}

HocSinh HocSinh::HSDiemTBCaoNhat() {
    if (sl == 0) { 
        cout << "Khong co hoc sinh!" ;
        return HocSinh();
    }

    
    HocSinh tmp = *ds[0];

    for (int i = 1; i < sl; i++) {
        if (ds[i]->dtb > tmp.dtb || (ds[i]->dtb == tmp.dtb && ds[i]->ms < tmp.ms)) {
            tmp = *ds[i];
        }
    }
    return tmp;
}

void HocSinh::In(ostream &os) {
     os << "HS: " << name << ", MS: " << mssv << ", DTB: " << fixed << setprecision(2) << dtb;
}

HocSinh::~HocSinh() {
    sl --;
}