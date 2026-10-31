#pragma once

#include <iostream>
using namespace std;

class Fraction{
private:
    int nume;
    int deno;
public:
    Fraction();
    Fraction(int a, int b);

    void input();
    void output();

    void setNum(int a);
    int getNum();
    void setDenom(int b);
    int getDenom();

    void reduce();
    void inverse();
    Fraction add(Fraction a2);
    
    int compare(Fraction a2); // 0 : first = second ; -1: first < second; 1: first > second

};