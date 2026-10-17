#pragma once 

#include <iostream>
#include <sstream>

using namespace std;

class Fraction {
private: 
    int num;
    int denom;
public: 
    Fraction();
    Fraction(int a , int b);
    Fraction(int d);
    Fraction(const string& s);
    Fraction(const Fraction &a);
};