#include "vd6.h"
using namespace std;


int ThoiGian::toGiay() const
{
    return _gio * 3600 + _phut * 60 + _giay;
}

void ThoiGian::tuGiay(int tongGiay)
{
    if (tongGiay < 0)
    {
        tongGiay = 0;
    }
    _gio = tongGiay / 3600;
    tongGiay %= 3600;
    _phut = tongGiay / 60;
    _giay = tongGiay % 60;
}


ThoiGian::ThoiGian()
{
    _gio = 0;
    _phut = 0;
    _giay = 0;
}

ThoiGian::ThoiGian(int giay)
{
    tuGiay(giay);
}

ThoiGian::ThoiGian(int phut, int giay)
{
    int tongGiay = phut * 60 + giay;
    tuGiay(tongGiay);
}

ThoiGian::ThoiGian(int gio, int phut, int giay)
{
    int tongGiay = gio * 3600 + phut * 60 + giay;
    tuGiay(tongGiay);
}


ThoiGian ThoiGian::operator+(const ThoiGian& other) const
{
    return ThoiGian(this->toGiay() + other.toGiay());
}

ThoiGian ThoiGian::operator+(int giay) const
{
    return ThoiGian(this->toGiay() + giay);
}

ThoiGian operator+(int giay, const ThoiGian& tg)
{
    return tg + giay;
}

ThoiGian ThoiGian::operator-(const ThoiGian& other) const
{
    int diff = this->toGiay() - other.toGiay();
    return ThoiGian(diff < 0 ? 0 : diff);
}

ThoiGian ThoiGian::operator-(int giay) const
{
    int diff = this->toGiay() - giay;
    return ThoiGian(diff < 0 ? 0 : diff);
}

ThoiGian operator-(int giay, const ThoiGian& tg)
{
    int diff = giay - tg.toGiay();
    return ThoiGian(diff < 0 ? 0 : diff);
}

bool ThoiGian::operator<=(const ThoiGian& other) const
{
    return this->toGiay() <= other.toGiay();
}

bool ThoiGian::operator<=(int giay) const
{
    return this->toGiay() <= giay;
}

bool operator<=(int giay, const ThoiGian& tg)
{
    return giay <= tg.toGiay();
}

ostream& operator<<(ostream& os, const ThoiGian& tg)
{
    os << setfill('0') << setw(2) << tg._gio << ":"
       << setfill('0') << setw(2) << tg._phut << ":"
       << setfill('0') << setw(2) << tg._giay;
    return os;
}