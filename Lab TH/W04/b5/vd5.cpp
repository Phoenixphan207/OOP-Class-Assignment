#include "vd5.h"
SoNguyenLon SoNguyenLon::maxSNL("0");

string SoNguyenLon::reverseString(const string& str)
{
    string res = "";
    for (int i = (int)str.length() - 1; i >= 0; i--)
    {
        res += str[i];
    }
    return res;
}

void SoNguyenLon::removeLeadingZeros()
{
    size_t firstNonZero = digits.find_first_not_of('0');
    if (firstNonZero == string::npos)
    {
        digits = "0";
        isNegative = false;
    }
    else
    {
        digits = digits.substr(firstNonZero);
    }
}

void SoNguyenLon::updateMax()
{
    if (*this > maxSNL)
    {
        maxSNL = *this;
    }
}

string SoNguyenLon::addStrings(const string& num1, const string& num2)
{
    string res = "";
    int i = (int)num1.length() - 1;
    int j = (int)num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        res += to_string(sum % 10);
    }
    return reverseString(res);
}

bool SoNguyenLon::isGreaterOrEqual(const string& num1, const string& num2)
{
    if (num1.length() != num2.length())
        return num1.length() > num2.length();
    return num1 >= num2;
}

string SoNguyenLon::subtractStrings(const string& num1, const string& num2)
{
    string res = "";
    int i = (int)num1.length() - 1;
    int j = (int)num2.length() - 1;
    int borrow = 0;

    while (i >= 0)
    {
        int sub = (num1[i--] - '0') - borrow - (j >= 0 ? (num2[j--] - '0') : 0);
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        res += to_string(sub);
    }
    return reverseString(res);
}


SoNguyenLon::SoNguyenLon()
{
    digits = "0";
    isNegative = false;
    updateMax();
}

SoNguyenLon::SoNguyenLon(long long val)
{
    if (val < 0)
    {
        isNegative = true;
        digits = to_string(-val);
    }
    else
    {
        isNegative = false;
        digits = to_string(val);
    }
    updateMax();
}

SoNguyenLon::SoNguyenLon(int digit, int count)
{
    isNegative = false;
    if (count <= 0)
    {
        digits = "0";
    }
    else
    {
        digits = string(count, '0' + abs(digit));
    }
    removeLeadingZeros();
    updateMax();
}

SoNguyenLon::SoNguyenLon(const string& val)
{
    if (val.empty())
    {
        digits = "0";
        isNegative = false;
    }
    else if (val[0] == '-')
    {
        isNegative = true;
        digits = val.substr(1);
    }
    else
    {
        isNegative = false;
        digits = val;
    }
    removeLeadingZeros();
    updateMax();
}

SoNguyenLon SoNguyenLon::SNLMax()
{
    return maxSNL;
}


bool SoNguyenLon::operator>(const SoNguyenLon& other) const
{
    if (isNegative != other.isNegative)
        return !isNegative;

    if (!isNegative) 
    {
        if (digits.length() != other.digits.length())
            return digits.length() > other.digits.length();
        return digits > other.digits;
    }
    else 
    {
        if (digits.length() != other.digits.length())
            return digits.length() < other.digits.length();
        return digits < other.digits;
    }
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& other) const
{
    SoNguyenLon res;
    if (isNegative == other.isNegative)
    {
        res.digits = addStrings(digits, other.digits);
        res.isNegative = isNegative;
    }
    else
    {
        if (isGreaterOrEqual(digits, other.digits))
        {
            res.digits = subtractStrings(digits, other.digits);
            res.isNegative = isNegative;
        }
        else
        {
            res.digits = subtractStrings(other.digits, digits);
            res.isNegative = other.isNegative;
        }
    }
    res.removeLeadingZeros();
    res.updateMax();
    return res;
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& other) const
{
    SoNguyenLon temp = other;
    if (temp.digits != "0")
    {
        temp.isNegative = !temp.isNegative;
    }
    return *this + temp;
}

SoNguyenLon SoNguyenLon::operator+(long long val) const
{
    return *this + SoNguyenLon(val);
}

SoNguyenLon SoNguyenLon::operator-(long long val) const
{
    return *this - SoNguyenLon(val);
}

SoNguyenLon operator+(long long val, const SoNguyenLon& snl)
{
    return SoNguyenLon(val) + snl;
}

SoNguyenLon operator-(long long val, const SoNguyenLon& snl)
{
    return SoNguyenLon(val) - snl;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl)
{
    if (snl.isNegative && snl.digits != "0")
    {
        os << "-";
    }
    os << snl.digits;
    return os;
}