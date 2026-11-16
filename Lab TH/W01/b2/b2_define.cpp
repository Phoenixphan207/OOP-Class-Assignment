#include <iostream>
#include <cstdlib> // abs, atoi
#include <cstring> // strpbrk
#include "b2.h"

using namespace std;

void Ngay::ChuanHoa()
{
    _ng = abs(_ng);
    _th = abs(_th);
    _n = abs(_n);

    if (_ng == 0) _ng = 1;
    if (_th == 0) _th = 1;
    if (_n == 0)  _n = 1;

    int thangDu = (_ng - 1) / 30;
    _ng = (_ng - 1) % 30 + 1;
    _th += thangDu;

    int namDu = (_th - 1) / 12;
    _th = (_th - 1) % 12 + 1;
    _n += namDu;
}

Ngay::Ngay()
{
    _ng = _th = _n = 1;
}

Ngay::Ngay(const int& x)
{
    _ng = abs(x);
    _th = _n = 1;
    ChuanHoa();
}

Ngay::Ngay(const int& ng, const int& th, const int& n) {
    _ng = abs(ng);
    _th = abs(th);
    _n = abs(n);
    ChuanHoa();
}

Ngay::Ngay(const char* s) {
    _ng = _th = _n = 1;
    const char* deli = "-/";
    const char* curr = s;
    if (curr) {
        _ng = atoi((curr));
        curr = strpbrk(curr, deli);
    }

    if (curr) {
        _th = atoi(curr + 1);
        curr = strpbrk(curr + 1 , deli);
    }
    if (curr) {
        _n = atoi(curr + 1);
    }
    ChuanHoa();
}

Ngay::~Ngay() {

} 

void Ngay::Xuat() {
    cout << _ng << "/" << _th << "/" << _n;
}