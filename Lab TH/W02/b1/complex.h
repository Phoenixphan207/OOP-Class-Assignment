#pragma once
#include <iostream>

class SoPhuc {
private:
    int thuc, ao;
    int sl = 0;
    static int ssl;
public:
    SoPhuc();
    SoPhuc(int th, int a);
    SoPhuc(const SoPhuc& sp);
    ~SoPhuc();

    SoPhuc Cong(const SoPhuc& sp) const;
    int SoLuongSP() const;
    static int SSoLuongSP();
};