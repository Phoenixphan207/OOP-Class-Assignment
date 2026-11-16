#pragma once
#include <iostream>
using namespace std;

class Ngay
{
private:
    int _ngay, _thang, _nam;

    bool laNamNhuan(int nam) const;
    int soNgayTrongThang(int thang, int nam) const;
    void chuanHoa(); 

public:
    Ngay();                                
    Ngay(int ngay);                        
    Ngay(int ngay, int thang, int nam);     

    Ngay operator+(const Ngay& other) const; 
    Ngay operator+(int soNgay) const;       
    friend Ngay operator+(int soNgay, const Ngay& ngay); 

    Ngay operator-(int soNgay) const;       
    int operator-(const Ngay& other) const;  
    friend Ngay operator-(int soNgay, const Ngay& ngay); 

    bool operator>(const Ngay& other) const; 

    friend ostream& operator<<(ostream& os, const Ngay& ngay);
};