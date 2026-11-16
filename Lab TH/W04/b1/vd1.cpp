#include "vd1.h"
#include <cmath>
using namespace std; 

SoPhuc::SoPhuc()
{
    _thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int &t, const int &a)
{
    _thuc = t;
    _ao = a;
}

SoPhuc SoPhuc::operator+(const int& n)
{
    SoPhuc rt = *this;
    rt._thuc += n;
    return rt;
}

void SoPhuc::operator<<(ostream& os)
{
    os << _thuc;
    if (_ao != 0)
    {
        os << ((_ao > 0) ? " + " : " - ") << abs(_ao) << "*i";
    }
}