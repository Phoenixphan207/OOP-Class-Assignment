#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct NgayThang {
    int ngay;
    int thang;
    int nam;

    NgayThang();
    NgayThang(int a, int b, int c);
    
    static bool LaNamNhuan(int n);
    static int SoNgayTrongThang(int t, int n);
    
    void ChuanHoa();
};

class SinhVien {
private:
    string mssv;
    string name;
    NgayThang day;
    float dlt;
    float dth;

    float ChuanHoaDiem(float diem);

public:
    SinhVien();
    SinhVien(const string& s);
    SinhVien(const string& s, const string& a, float lt, float th);
    SinhVien(const string& s, const string& a, float lt, float th, int ng, int thg, int n);
    SinhVien(const string& s, const string& a, float lt, float th, NgayThang n);
    SinhVien(const SinhVien& a);

    void Xuat();
};