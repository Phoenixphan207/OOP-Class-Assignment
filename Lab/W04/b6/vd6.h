#pragma once 

#include <iostream>
#include <iomanip>

using namespace std;

class ThoiGian
{
private:
    int _gio;
    int _phut;
    int _giay;

    int toGiay() const;
    void tuGiay(int tongGiay);

public:
    ThoiGian();
    ThoiGian(int giay);
    ThoiGian(int phut, int giay);
    ThoiGian(int gio, int phut, int giay);

    ThoiGian operator+(const ThoiGian& other) const;
    ThoiGian operator+(int giay) const;
    friend ThoiGian operator+(int giay, const ThoiGian& tg);

    ThoiGian operator-(const ThoiGian& other) const;
    ThoiGian operator-(int giay) const;
    friend ThoiGian operator-(int giay, const ThoiGian& tg);

    bool operator<=(const ThoiGian& other) const;
    bool operator<=(int giay) const;
    friend bool operator<=(int giay, const ThoiGian& tg);

    friend ostream& operator<<(ostream& os, const ThoiGian& tg);
};