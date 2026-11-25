#include "b1.h"
using namespace std;

void Ngay::Xuat() {
    cout << ngay << "::" << thang << "::" << nam << endl;
}

Ngay::Ngay() {
    ngay = thang = nam = 1;

}

bool nam_nhuan(int a) {
    return (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0));
}

int day_in_month(int a, int nam) {
    switch(a) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return (nam_nhuan(nam)) ? 29 : 28;
        default:
            break;
    }
    return 1;
}

void Ngay::ChuanHoa() {
    nam = abs(nam);

    while (thang <= 0) {
        thang += 12;
        nam --;
    }
    while (thang > 12) {
        thang -= 12;
        nam ++;
    }

    while (ngay <= 0) {
        thang --;
        if (thang == 0) {
            thang = 12;
            nam -= 1;
        }

        ngay += day_in_month(thang, nam);

    }

    while (ngay > day_in_month(thang, nam)) {
        ngay -= day_in_month(thang ,nam);
        thang += 1;
        
        if (thang == 13) {
            thang = 1;
            nam += 1;
        }
    }
}

Ngay::Ngay(int a, int b, int c) {
    ngay = a;
    thang = b;
    nam = c;
    ChuanHoa();
}

Ngay::Ngay(int a) {
    ngay = a;
    thang = 1;
    nam = 1;

    ChuanHoa();
}

Ngay::Ngay(const string &s) {
    sscanf(s.c_str() , "%d-%d-%d", &ngay, &thang, &nam);
    ChuanHoa();
}

