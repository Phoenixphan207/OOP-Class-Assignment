#pragma once
#include <ostream>
#include <iostream>
using namespace std;


class Frac{
private:
    int tu;
    int mau;

public:
    Frac(): tu(1) , mau(1) {};
    Frac(int a): tu(a), mau(1) {};
    void reduce();
    Frac operator+(const Frac& a1) const;
    Frac operator-(const Frac& a1) const ;
    Frac operator*(const Frac& a1) const ;
    Frac operator/(const Frac& a1) const ;

    bool operator>(const Frac& a1) const ;
    bool operator<(const Frac& a1) const ;
    bool operator==(const Frac& a1) const ;
    bool operator>=(const Frac& a1) const ;
    bool operator<=(const Frac& a1) const ;
    bool operator!=(const Frac& a1) const ;

    Frac& operator=(const Frac& a1);
    Frac& operator+=(const Frac& a1);
    Frac& operator*=(const Frac& a1);
    
    Frac& operator++();
    Frac& operator--();

    friend ostream& operator<<(ostream& os, const Frac& a1);
    friend istream& operator>>(istream& is, Frac& a1);

 
};