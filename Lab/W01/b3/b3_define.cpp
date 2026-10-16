#include "b3.h"

ThoiGian::ThoiGian() {
    gio = phut = giay = 0;
}

ThoiGian::ThoiGian(int a) {
    gio = 0;
    phut = a / 60;
    giay = a % 60;
}

ThoiGian::ThoiGian(int a , int b) {
    gio = a / 60;
    phut = a % 60;
    giay = b;
}

ThoiGian::ThoiGian(int a, int b, int c) {
    gio = a + b / 60;
    phut = b % 60;

    giay = (c < 0) ? 0 : c;

}

int len(int a) {
    int d = 0;
    while (a > 0) {
        a /= 10;
        d ++;
    }
    return d;
}

void ThoiGian::Xuat() {
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", gio, phut, giay);
    cout << buffer << endl;
}