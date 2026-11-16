#include "frac.h"

Fraction::Fraction() {
    num = 0;
    denom = 1;
}

Fraction::Fraction(int a , int b) {
    num = a;
    if (b == 0) {
        cout << "ERROR parameter!, auto define 0/1";
        num = 0;
        denom = 1;
    }

    else denom = b;
}

Fraction::Fraction(int d) {
    num = d;
    denom = 1;
}

Fraction::Fraction(const string& s) {
    string tmp = s;
    for (char c : tmp) {
        if (c == '/') c = ' ' ;
    }

    stringstream ss(tmp);
    ss >> num >> denom;
}

Fraction::Fraction(const Fraction& a) {
    num = a.num;
    denom = a.denom;
}
