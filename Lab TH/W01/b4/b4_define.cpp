#include "b4.h"

bool NgayThang::LaNamNhuan(int n) {
    return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

int NgayThang::SoNgayTrongThang(int t, int n) {
    switch (t) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return LaNamNhuan(n) ? 29 : 28;
        default:
            return 30;
    }
}

void NgayThang::ChuanHoa() {
    if (nam < 1) nam = 1;

    if (thang > 12) {
        nam += (thang - 1) / 12;
        thang = (thang - 1) % 12 + 1;
    } else if (thang < 1) {
        thang = 1;
    }

    while (ngay > SoNgayTrongThang(thang, nam)) {
        ngay -= SoNgayTrongThang(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
    if (ngay < 1) ngay = 1;
}

NgayThang::NgayThang() {
    ngay = 1;
    thang = 1;
    nam = 1;
}

NgayThang::NgayThang(int a, int b, int c) {
    ngay = a;
    thang = b;
    nam = c;
    ChuanHoa(); 
}


float SinhVien::ChuanHoaDiem(float diem) {
    if (diem < 0.0f) return 0.0f;
    if (diem > 10.0f) return 10.0f;
    return diem;
}

SinhVien::SinhVien() {
    mssv = "xxxxxxx";
    name = "xxxx";
    day = NgayThang(1, 1, 2000); // giả định ngày tháng mặc định 1/1/2000
    dlt = 10.0f;
    dth = 10.0f;
}

SinhVien::SinhVien(const string& s) {
    mssv = s;
    name = "xxxx";
    day = NgayThang(1, 1, 2000);
    dlt = 10.0f;
    dth = 10.0f;
}

SinhVien::SinhVien(const string& s, const string& a, float lt, float th) {
    mssv = s;
    name = a;
    day = NgayThang(1, 1, 2000);
    dlt = ChuanHoaDiem(lt);
    dth = ChuanHoaDiem(th);
}

SinhVien::SinhVien(const string& s, const string& a, float lt, float th, int ng, int thg, int n) {
    mssv = s;
    name = a;
    day = NgayThang(ng, thg, n); 
    dlt = ChuanHoaDiem(lt);
    dth = ChuanHoaDiem(th);
}

SinhVien::SinhVien(const string& s, const string& a, float lt, float th, NgayThang n) {
    mssv = s;
    name = a;
    day = n;
    day.ChuanHoa(); 
    dlt = ChuanHoaDiem(lt);
    dth = ChuanHoaDiem(th);
}

SinhVien::SinhVien(const SinhVien& a) {
    mssv = a.mssv;
    name = a.name;
    day = a.day;
    dlt = a.dlt;
    dth = a.dth;
}

void SinhVien::Xuat() {
    cout << "MSSV: \"" << mssv << "\", HoTen: \"" << name << "\"\n";
    
    cout << "NgaySinh: " 
         << setfill('0') << setw(2) << day.ngay << "/"
         << setfill('0') << setw(2) << day.thang << "/"
         << setfill('0') << setw(4) << day.nam
         << ", DLT: " << dlt << ", DTH: " << dth << endl;
}