#pragma once

#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int&);
    SoPhuc(const int&, const int&);
    SoPhuc operator+(const SoPhuc&);

    void operator<<(ostream&);
};