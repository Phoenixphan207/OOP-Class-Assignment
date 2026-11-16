#include "vd3.h"


SoPhuc::SoPhuc()
{
    _thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int &t) : SoPhuc()
{
    _thuc = t;
}

SoPhuc::SoPhuc(const int &t, const int &a)
{
    _thuc = t;
    _ao = a;
}

SoPhuc operator+(const int &n, const SoPhuc &sp)
{
    SoPhuc spR(n);
    spR._thuc += sp._thuc;
    spR._ao += sp._ao;
    return spR;
}

ostream& operator<<(ostream &os, const SoPhuc &sp)
{
    os << sp._thuc;
    if (sp._ao != 0)
    {
        os << ((sp._ao > 0) ? " + " : " - ") << abs(sp._ao) << "*i";
    }
    return os;
}