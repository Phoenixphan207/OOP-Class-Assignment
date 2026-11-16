#include "songuyenlon.h"

SoNguyenLon SoNguyenLon::maxObj = SoNguyenLon("0");

void SoNguyenLon::daoNguocChuoi(string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void SoNguyenLon::normalize() {
    while (val.length() > 1 && val[0] == '0') {
        val.erase(0, 1);
    }
}

bool SoNguyenLon::soNhanHon(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

void SoNguyenLon::updateMax() {
    if (maxObj.val == "0" && val == "0") return;
    if (soNhanHon(maxObj.val, val)) {
        maxObj = *this;
    }
}

SoNguyenLon::SoNguyenLon() {
    val = "0";
    updateMax();
}

SoNguyenLon::SoNguyenLon(string s) {
    val = s.empty() ? "0" : s;
    normalize();
    updateMax();
}

SoNguyenLon::SoNguyenLon(int d, int len) {
    if (len <= 0) {
        val = "0";
    } else {
        val = string(len, '0' + d);
    }
    normalize();
    updateMax();
}

void SoNguyenLon::In(ostream& os) const {
    os << val;
}

SoNguyenLon SoNguyenLon::SNLMax() {
    return maxObj;
}

SoNguyenLon SoNguyenLon::Cong(long long num) const {
    string b = to_string(num);
    string a = val;

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string res = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        res += to_string(sum % 10);
    }

    daoNguocChuoi(res);
    return SoNguyenLon(res);
}

SoNguyenLon SoNguyenLon::HieuVoiHangSo(long long hangSo, const SoNguyenLon& snl) {
    SoNguyenLon numA(to_string(hangSo));
    return numA.Tru(snl);
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon& other) const {
    string a = val;
    string b = other.val;

    if (soNhanHon(a, b)) {
        return SoNguyenLon("0");
    }

    int i = a.length() - 1;
    int j = b.length() - 1;
    int borrow = 0;
    string res = "";

    while (i >= 0) {
        int sub = (a[i--] - '0') - borrow;
        if (j >= 0) {
            sub -= (b[j--] - '0');
        }

        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res += to_string(sub);
    }

    daoNguocChuoi(res);
    return SoNguyenLon(res);
}
