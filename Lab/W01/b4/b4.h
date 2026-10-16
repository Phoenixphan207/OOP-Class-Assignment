#pragma once 
#include <iostream>
using namespace std;

struct NgayThang {
    int ngay;
    int thang;
    int nam;
    NgayThang(): ngay(1) , thang(1) , nam(1) {};
    NgayThang(int a, int b, int c): ngay(a), thang(b), nam(c) {};
};

class SinhVien{
private:
    string mssv;
    string name;
    NgayThang day;
    float dlt;
    float dth;
public: 
    SinhVien();
    SinhVien(const string& s);
    SinhVien(const string& s, const string& a, float lt, float th);
    SinhVien(const string& s, const string& a, float lt, float th, int ng, int thg, int n);
    SinhVien(const string& s, const string& a, float lt, float th, NgayThang n);
    SinhVien(const SinhVien& a);

    void Xuat();
};