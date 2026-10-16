#include "b4.h"

SinhVien::SinhVien(){
    mssv = "";
    name = "";
    day = NgayThang();
    dlt = 10.0;
    dth = 10.0;
}

SinhVien::SinhVien(const string& s) {
    mssv = s;
    name = "";
    day = NgayThang();
    dlt = 10.0;
    dth = 10.0;
}

SinhVien::SinhVien(const string& s, const string& a, float lt, float th) {
    mssv = s;
    name = a;
    day = NgayThang();
    dlt = lt;
    dth = th;
}

SinhVien::SinhVien(const string& s, const string& a, float lt, float th, int ng, int thg, int n) {
    mssv = s;
    name = a;
    day = NgayThang(ng, thg, n);
    dlt = lt;
    dth = th;
}

SinhVien::SinhVien(const string& s, const string& a, float lt, float th, NgayThang n) {
    mssv = s;
    name = a;
    day = n;
    dlt = lt;
    dth = th;
}

SinhVien::SinhVien(const SinhVien& a) {
    mssv =a.mssv;
    name = a.name;
    day = a.day;
    dlt = a.dlt;
    dth = a.dth;
}

void SinhVien::Xuat() {
    cout << "MSSV: " << mssv << "," << " HoTen: " << name 
         << '\n' << "NgaySinh: " << this->day.ngay << "/" << this->day.thang << "/" 
         << this->day.nam << ", DLT: " << dlt << ", DTH: " << dth;
    cout << endl;
}