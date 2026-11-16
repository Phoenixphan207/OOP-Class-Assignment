#pragma once 
#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc
{
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int&);
    SoPhuc(const int&, const int&);

    friend SoPhuc operator+(const int&, const SoPhuc&);
    friend ostream& operator<<(ostream&, const SoPhuc&);
};