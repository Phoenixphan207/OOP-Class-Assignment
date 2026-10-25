#include "student.h"
using namespace std;

HocSinh HocSinh::ds[100];
int HocSinh::sl = 0;
int HocSinh::mssv = 23120000;

static bool is_ds_initialized = false;

void chuan_hoa(float& a, float& b, float& c) {
    a = (a < 0) ? 0 : ((a > 10) ? 10 : a);
    b = (b < 0) ? 0 : ((b > 10) ? 10 : b);
    c = (c < 0) ? 0 : ((c > 10) ? 10 : c);
}

HocSinh::HocSinh() {
    name = "";
    d1 = 0.0f;
    d2 = 0.0f;
    d3 = 0.0f;
    dtb = 0.0f;
    
    if (is_ds_initialized) {
        mssv++;
        ms = mssv;
        if (sl < 100) {
            ds[sl++] = *this;
        }
    } else {
        ms = 0; 
    }
}

HocSinh::HocSinh(const char* s, float a, float b, float c) {
    name = s;
    chuan_hoa(a, b, c);

    d1 = a;
    d2 = b;
    d3 = c;
    dtb = (a + b + c) / 3.0f;

    mssv++;
    ms = mssv;

    if (sl < 100) {
        ds[sl++] = *this;
    }
}

void HocSinh::DatHoTen(const char* s) {
    name = s;
    for (int i = 0; i < sl; i++) {
        if (ds[i].ms == this->ms) {
            ds[i].name = this->name;
            break;
        }
    }
}

void HocSinh::GanDiem(float a, float b, float c) {
    chuan_hoa(a, b, c);

    d1 = a;
    d2 = b;
    d3 = c;
    dtb = (a + b + c) / 3.0f;

    for (int i = 0; i < sl; i++) {
        if (ds[i].ms == this->ms) {
            ds[i] = *this;
            break;
        }
    }
}

void HocSinh::In(ostream& os) {
    os << "HS: " << name << ", MS: " << ms << ", DTB: " << fixed << setprecision(2) << dtb;
}

HocSinh HocSinh::HSDiemTBCaoNhat() {
    if (sl == 0) {
        return HocSinh();
    }
    
    int maxIdx = 0;
    for (int i = 1; i < sl; i++) {
        if (ds[i].dtb > ds[maxIdx].dtb) {
            maxIdx = i;
        }
    }
    return ds[maxIdx];
}

struct InitDsHelper {
    InitDsHelper() {
        is_ds_initialized = true;
    }
};
static InitDsHelper helper;