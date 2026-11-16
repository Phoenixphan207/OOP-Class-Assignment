#include "vd4.h"

bool Ngay::laNamNhuan(int nam) const
{
    return (nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0));
}

int Ngay::soNgayTrongThang(int thang, int nam) const
{
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (laNamNhuan(nam)) 
                return 29;
            return 28;
        default:
            return 0;
    }
}

void Ngay::chuanHoa()
{
    while (this->_thang > 12)
    {
        this->_thang -= 12;
        this->_nam++;
    }
    while (this->_thang < 1)
    {
        this->_thang += 12;
        this->_nam--;
    }

    while (this->_ngay > soNgayTrongThang(this->_thang, this->_nam))
    {
        this->_ngay -= soNgayTrongThang(this->_thang, this->_nam);
        this->_thang++;
        if (this->_thang > 12)
        {
            this->_thang = 1;
            this->_nam++;
        }
    }

    while (this->_ngay < 1)
    {
        this->_thang--;
        if (this->_thang < 1)
        {
            this->_thang = 12;
            this->_nam--;
        }
        this->_ngay += soNgayTrongThang(this->_thang, this->_nam);
    }
}

Ngay::Ngay()
{
    _ngay = 1;
    _thang = 1;
    _nam = 1;

}

Ngay::Ngay(int ngay)
{
    this->_ngay = ngay;
    this->_thang = 1;
    this->_nam = 1;
    chuanHoa();
}

Ngay::Ngay(int ngay, int thang, int nam)
{
    this->_ngay = ngay;
    this->_thang = thang;
    this->_nam = nam;
    chuanHoa();
}

Ngay Ngay::operator+(const Ngay& other) const
{
    Ngay res;
    res._ngay = this->_ngay + other._ngay;
    res._thang = this->_thang + other._thang;
    res._nam = this->_nam + other._nam;
    res.chuanHoa();
    return res;
}

Ngay Ngay::operator+(int soNgay) const
{
    Ngay res = *this;
    res._ngay += soNgay;
    res.chuanHoa();
    return res;
}

Ngay operator+(int soNgay, const Ngay& ngay)
{
    return ngay + soNgay;
}

Ngay Ngay::operator-(int soNgay) const
{
    Ngay res = *this;
    res._ngay -= soNgay;
    res.chuanHoa();
    return res;
}

int Ngay::operator-(const Ngay& other) const
{
    int ngay1 = this->_ngay;
    Ngay temp1(1, 1, this->_nam);
    for (int m = 1; m < this->_thang; m++)
        ngay1 += soNgayTrongThang(m, this->_nam);
    ngay1 += (this->_nam - 1) * 365;

    int ngay2 = other._ngay;
    for (int m = 1; m < other._thang; m++)
        ngay2 += soNgayTrongThang(m, other._nam);
    ngay2 += (other._nam - 1) * 365;

    return ngay1 - ngay2;
}

Ngay operator-(int soNgay, const Ngay& ngay)
{
    Ngay temp(soNgay);
    Ngay res;
    res._ngay = temp._ngay - ngay._ngay;
    res._thang = temp._thang - ngay._thang;
    res._nam = temp._nam - ngay._nam;
    res.chuanHoa();
    return res;
}

bool Ngay::operator>(const Ngay& other) const
{
    if (this->_nam != other._nam)
        return this->_nam > other._nam;
    if (this->_thang != other._thang)
        return this->_thang > other._thang;
    return this->_ngay > other._ngay;
}

ostream& operator<<(ostream& os, const Ngay& ngay)
{
    os << ngay._ngay << "/" << ngay._thang << "/" << ngay._nam;
    return os;
}