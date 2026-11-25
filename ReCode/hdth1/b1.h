#pragma once

#include <iostream>
#include <cstdio>
class Ngay{
private:
    int ngay;
    int thang;
    int nam;
public:
    Ngay();
    Ngay(int a, int b, int c);
    Ngay(int a);
    Ngay(const std::string& tmp);

    void ChuanHoa();
    void Xuat();
};