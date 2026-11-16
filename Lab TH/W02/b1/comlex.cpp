#include "complex.h"
using namespace std;

SoPhuc::SoPhuc() {
    thuc = 0;
    ao = 0;
    sl ++;
    ssl ++;
}

SoPhuc::SoPhuc(int th, int a) {
    thuc = th;
    ao = a;
    sl ++;
    ssl ++;
}

SoPhuc::SoPhuc(const SoPhuc& sp ) {
    thuc = sp.thuc;
    ao = sp.ao;
    sl ++;
    ssl ++;
}

SoPhuc::~SoPhuc() {
    sl --;
    ssl --;
}

SoPhuc SoPhuc::Cong(const SoPhuc& sp) const{ 
    SoPhuc kq(*this);
    
    kq.thuc = sp.thuc;
    kq.ao = sp.ao;

    return kq;
}

int SoPhuc::SoLuongSP() const {
    return sl;
}

int SoPhuc::SSoLuongSP() {
    return ssl;
}