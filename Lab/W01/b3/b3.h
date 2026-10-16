#pragma once 
#include <iostream>
#include <cstdio>

using namespace std;


class ThoiGian {
private: 
    int gio;
    int phut;
    int giay;
public: 
    ThoiGian();
    ThoiGian(int a);
    ThoiGian(int a , int b);
    ThoiGian(int a , int b , int c);

    void Xuat();
};