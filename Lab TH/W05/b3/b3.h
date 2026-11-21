#pragma once 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "b3_sllist.h"

class SoNguyenLon
{
private:
    SLList<unsigned char> lCS;
    void Pow10(const int& n);

public:
    SoNguyenLon(void);
    SoNguyenLon(const int& cs, const int& scs);
    SoNguyenLon(const unsigned long& n);
    SoNguyenLon(const SoNguyenLon& snl);
    SoNguyenLon(const char* s);
    ~SoNguyenLon(void);

    int SoCS() const;
    SoNguyenLon operator+(SoNguyenLon snl);
    SoNguyenLon operator-(SoNguyenLon snl);
    SoNguyenLon operator*(SoNguyenLon snl);
    bool operator>(const SoNguyenLon& snl) const;
    SoNguyenLon& operator=(const SoNguyenLon& snl);
    SoNguyenLon& operator+=(SoNguyenLon snl);

    friend SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl);
    friend SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl);
    friend std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl);
};
