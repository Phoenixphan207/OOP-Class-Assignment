#include "frac.h"

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b > 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void Frac::reduce() {
    int d = gcd(tu , mau);

    tu/= d;
    mau /= d;
}

Frac Frac::operator+(const Frac& a1) const {
    Frac c;
    c.tu = this->tu * a1.mau + this->mau * a1.tu;
    c.mau = this->mau * a1.mau;
    c.reduce();

    return c;
}

Frac Frac::operator-(const Frac& a1) const{
    Frac c;
    c.tu = this->tu * a1.mau - this->mau * a1.tu;
    c.mau = this->mau * a1.mau;
    c.reduce();

    return c;
}

Frac Frac::operator*(const Frac& a1) const {
    Frac c;
    c.tu = this->tu * a1.tu;
    c.mau = this->mau * a1.mau;
    c.reduce();

    return c;
}

Frac Frac::operator/(const Frac& a1) const {
    Frac c;
    c.tu = this->tu * a1.mau;
    c.mau = this->mau * a1.tu;
    c.reduce();

    return c;
}

bool Frac::operator>(const Frac& a1) const {
    return ((this->tu * a1.mau) > (this->mau * a1.tu));
}

bool Frac::operator<(const Frac& a1) const {
    return ((this->tu * a1.mau) < (this->mau * a1.tu));
}

bool Frac::operator==(const Frac& a1) const { 
    return ((this->tu * a1.mau) == (this->mau * a1.tu));
}

bool Frac::operator>=(const Frac& a1) const {
    return ((this->tu * a1.mau) >= (this->mau * a1.tu));
}

bool Frac::operator<=(const Frac& a1) const {
    return ((this->tu * a1.mau) <= (this->mau * a1.tu));
}

bool Frac::operator!=(const Frac& a1) const {
    return ((this->tu * a1.mau) != (this->mau * a1.tu));
}

Frac& Frac::operator=(const Frac& a1) {
    this->tu = a1.tu;
    this->mau = a1.mau;

    return *this;
}

Frac& Frac::operator+=(const Frac& a1) {
    *this = *this + a1; 
    return *this;       
}

Frac& Frac::operator*=(const Frac& a1) {
    *this = *this * a1;
    return *this;
}

Frac& Frac::operator++() {
    *this = *this + 1;

    return *this;
}

Frac& Frac::operator--() {
    *this = *this - 1;
    return *this;
}

ostream& operator<<(ostream& os, const Frac& a1) {
    os << a1.tu << "/" << a1.mau;
    return os;
}

istream& operator>>(istream& is, Frac& a1) {
    cout << "Nhap tu so: ";
    is >> a1.tu;
    
    cout << "Nhap mau so: ";
    is >> a1.mau;

    while (a1.mau == 0) {
        std::cout << "ERROR! Nhap lai mau so: ";
        is >> a1.mau;
    }

    return is;
}
