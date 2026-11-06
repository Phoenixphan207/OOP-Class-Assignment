#pragma once 
#include <iostream>

class SoPhuc
{
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int&);
    SoPhuc(const int&, const int&);
    SoPhuc operator+(const int&);

    void operator<<(std::ostream&);
};