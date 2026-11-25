#pragma once 

#include <iostream>
#include <fstream>
class Ngay{
private:
    int ngay;
    int thang;
    int nam;

public:
    Ngay();
    Ngay(int a, int b, int c);
    Ngay(int n);

    int to_ngay() const;
    Ngay tong_to_ngay(int tong);

    Ngay operator+(const Ngay& tmp) const;
    Ngay operator+(int n) const;
    Ngay operator-(const Ngay& tmp) const;
    Ngay operator-(int n) const;
    bool operator>(const Ngay& tmp) const;

    bool operator<(const Ngay&tmp) const;
    Ngay operator+=(int n);
    Ngay operator-=(int n);
    Ngay& operator++();
    Ngay operator++(int);
    Ngay operator--(int);
    Ngay& operator--();
    bool operator==(const Ngay& a1);
    bool operator!=(const Ngay& a1);


    friend Ngay operator+(const int& n , const Ngay& tmp);
    friend Ngay operator-(const int& n, const Ngay& tmp);
    friend std::ostream& operator<<(std::ostream& os, const Ngay& tmp);
    friend std::istream& operator>>(std::istream& is, Ngay& tmp);
};
