#include "ex2.4.h"

bool is_valid(int a , int b) {
    return (b != 0);
}

Fraction::Fraction() {
    nume = 0;
    deno = 1;
}
Fraction::Fraction(int a, int b) {
    nume = a;
    deno = b;
}

void Fraction::input() {
    cout << "Nhap tu so: ";
    cin >> nume;
    cout << "Nhap mau so: ";
    cin >> deno;

    while (!is_valid(nume ,deno))
    {
        cout << "Nhap lai mau so: ";
        cin >> deno;
    }
}

void Fraction::output() {
    cout << nume << "/" << deno << endl;
}

int Fraction::getNum() {
    return nume;
}
void Fraction::setNum(int a) {
    nume = a;
}

int Fraction::getDenom() {
    return deno;
}
void Fraction::setDenom(int b) {
    deno = b;
}

int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void Fraction::reduce() {
    int gcd = ucln(nume , deno);
    nume /= gcd;
    deno /= gcd;
}

void Fraction::inverse() {
    int c = nume;
    nume = deno;
    deno = c;
}

Fraction Fraction::add(Fraction a2) {
    if (!is_valid(a2.getNum() , a2.getDenom())) {
        cout << "ERROR";
        exit(-1);
    }

    Fraction c = Fraction();
    c.setNum(nume * a2.getDenom() + deno * a2.getNum());
    c.setDenom(deno * a2.getDenom());
    c.reduce();

    return c;
}

int Fraction::compare(Fraction a2) {
    if (!is_valid(a2.getNum() , a2.getDenom())) {
        cout << "ERROR";
        return -2;
    }

    Fraction::reduce();
    a2.reduce();

    int c1 = a2.getDenom() * nume;
    int c2 = deno * a2.getNum();

    if (c1 == c2) return 0;
    if (c1 < c2) return -1;
    if (c1 > c2) return 1;
}


