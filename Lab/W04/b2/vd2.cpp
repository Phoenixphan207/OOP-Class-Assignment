#include "vd2.h"
#include <cmath>

SoPhuc::SoPhuc()
{
    _thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int &t) : SoPhuc()
{
    cout << "using... ";
    _thuc = t;
}

SoPhuc::SoPhuc(const int &t, const int &a)
{
    _thuc = t;
    _ao = a;
}

SoPhuc SoPhuc::operator+(const SoPhuc &sp)
{
    SoPhuc rt = *this;
    rt._thuc += sp._thuc;
    rt._ao += sp._ao;
    return rt;
}

void SoPhuc::operator<<(ostream &os)
{
    os << _thuc;
    if (_ao != 0)
    {
        os << ((_ao > 0) ? " + " : " - ") << abs(_ao) << "*i";
    }
}