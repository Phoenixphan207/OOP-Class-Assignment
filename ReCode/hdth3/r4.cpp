#include "r4.h"

using namespace std;

bool nam_nhuan(int nam) {
    return (nam % 400 == 0 || nam % 4 == 0 && nam % 100 != 0);
}
int ngay_thang(int thang, int nam) {
    switch (thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return (nam_nhuan(nam)) ? 29 : 28;
    default:
        break;
    }
    return 0;
}

void chuan_hoa(int& ng, int& th, int & n) {
    ng = (ng == 0) ? 1 : abs(ng);
    th = (th == 0) ? 1 : abs(th);
    n = (n == 0) ? 1 : abs(n);

    while (th > 12) {
        th -= 12;
        n ++;
    }

    while (ng > ngay_thang(th, n)) {
        ng -= ngay_thang(th, n);
         
        th += 1;

        if (th > 12) {
            th = 1;
            n += 1;
        }
    }
}   

int Ngay::to_ngay() const {
    int s = 0;

    for (int i = 1 ; i < nam; i++) {
        s += (nam_nhuan(i)) ? 366 : 365;
    }

    for (int i = 1 ; i < thang; i++) {
        s += ngay_thang(i, nam);
    }

    s += ngay;
    return s;
}

Ngay Ngay::tong_to_ngay(int tong) {
    if (tong < 1) tong = 1; // Chặn dưới tối thiểu là 1/1/1

    nam = 1;
    while (true) {
        int ngayTrongNam = nam_nhuan(nam) ? 366 : 365;
        if (tong > ngayTrongNam) {
            tong -= ngayTrongNam;
            nam++;
        } else {
            break;
        }
    }

    thang = 1;
    while (true) {
        int ngayTrongThang = ngay_thang(thang, nam);
        if (tong > ngayTrongThang) {
            tong -= ngayTrongThang;
            thang++;
        } else {
            break;
        }
    }

    ngay = tong;
    return *this;
}


Ngay::Ngay() {
    ngay = thang = nam = 1;
}

Ngay::Ngay(int a, int b, int c) {
    ngay = a;
    thang = b;
    nam = c;
    chuan_hoa(ngay, thang, nam);
}

Ngay::Ngay(int n) {
    ngay = n;
    thang = 1;
    nam = 1;
    chuan_hoa(ngay , thang, nam);
}

Ngay Ngay::operator+(const Ngay& tmp) const {
    return Ngay(this->ngay + tmp.ngay , this->thang + tmp.thang, this->nam + tmp.nam);    
}       

Ngay Ngay::operator+(int n) const {
    return Ngay(this->to_ngay() + n);
}

Ngay operator+(const int& n , const Ngay& tmp)  {
    return (tmp + n);
}

Ngay Ngay::operator-(const Ngay& tmp) const {
    return this->to_ngay() - tmp.to_ngay();
}

Ngay Ngay::operator-(int n) const {
    return Ngay(this->to_ngay() - n);
}

Ngay operator-(const int& n, const Ngay& tmp) {
    return Ngay(n - tmp.to_ngay());
}

bool Ngay::operator>(const Ngay& tmp) const { 
    if (this->nam != tmp.nam) return this->nam > tmp.nam;
    if (this->thang != tmp.thang) return this->thang > tmp.thang;
    return this->ngay > tmp.ngay;
}

ostream& operator<<(ostream& os , const Ngay&tmp) {
    os << tmp.ngay << "/" << tmp.thang << "/" << tmp.nam;
    return os;
}

bool Ngay::operator<(const Ngay& tmp ) const {
    if (this->nam != tmp.nam) return this->nam < tmp.nam;
    if (this->thang != tmp.thang) return this->thang < tmp.thang;
    return this->ngay < tmp.ngay;
}

Ngay Ngay::operator+=(int n) {
    Ngay tmp;
    tmp = this->to_ngay() + n;
    return tmp;
}

Ngay Ngay::operator-=(int n) {
    Ngay tmp;
    tmp = this->to_ngay() - n;
    return tmp;
}

Ngay& Ngay::operator++() {
    *this += 1;
    return *this;
}

Ngay Ngay::operator++(int) {
    Ngay tmp = *this;
    *this += 1;
    return tmp;
}

Ngay Ngay::operator--(int) {
    Ngay tmp = *this;
    *this -= 1;
    return tmp;
} 

Ngay& Ngay::operator--(){
    *this -= 1;
    return *this;
}

istream& operator>>(istream& is, Ngay&tmp) {
    char slash;
    is >> tmp.ngay >> slash >> tmp.thang >> slash >> tmp.nam;
    
}
