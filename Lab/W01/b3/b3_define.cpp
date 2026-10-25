#include "b3.h"

void ThoiGian::ChuanHoa(long long tongGiay) {
    if (tongGiay < 0) {
        tongGiay = 0; 
    }

    gio = (tongGiay / 3600) % 24;   
    phut = (tongGiay % 3600) / 60; 
    giay = tongGiay % 60;           
}


ThoiGian::ThoiGian() {
    ChuanHoa(0);
}

ThoiGian::ThoiGian(int a) {
    ChuanHoa(a);
}

ThoiGian::ThoiGian(int a, int b) {
    long long tongGiay = (long long)a * 60 + b;
    ChuanHoa(tongGiay);
}

ThoiGian::ThoiGian(int a, int b, int c) {
    long long tongGiay = (long long)a * 3600 + (long long)b * 60 + c;
    ChuanHoa(tongGiay);
}

void ThoiGian::Xuat() {
    char buffer[32]; 
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", gio, phut, giay);
    cout << buffer << endl;
}