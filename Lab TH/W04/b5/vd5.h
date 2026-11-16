#pragma once 

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

class SoNguyenLon
{
private:
    string digits;    
    bool isNegative;  

    static SoNguyenLon maxSNL; 

    void updateMax();
    void removeLeadingZeros();

    static string reverseString(const string& str);
    static string addStrings(const string& num1, const string& num2);
    static string subtractStrings(const string& num1, const string& num2);
    static bool isGreaterOrEqual(const string& num1, const string& num2);

public:
    SoNguyenLon();
    SoNguyenLon(long long val);
    SoNguyenLon(int digit, int count);
    SoNguyenLon(const string& val);

    static SoNguyenLon SNLMax();

    SoNguyenLon operator+(const SoNguyenLon& other) const;
    SoNguyenLon operator-(const SoNguyenLon& other) const;

    SoNguyenLon operator+(long long val) const;
    SoNguyenLon operator-(long long val) const;

    friend SoNguyenLon operator+(long long val, const SoNguyenLon& snl);
    friend SoNguyenLon operator-(long long val, const SoNguyenLon& snl);

    bool operator>(const SoNguyenLon& other) const;

    friend ostream& operator<<(ostream& os, const SoNguyenLon& snl);
};