#include "b4.h"

MyString::MyString() {}

MyString::MyString(const char* s)
{
    if (s == nullptr)
    {
        return;
    }
    int len = std::strlen(s);
    for (int i = 0; i < len; ++i)
    {
        lChar.push_back(s[i]);
    }
}

MyString::MyString(const MyString& ms)
{
    lChar = ms.lChar;
}

MyString::~MyString()
{
}

MyString& MyString::operator=(const MyString& ms)
{
    if (this == &ms)
    {
        return *this;
    }
    lChar = ms.lChar;
    return *this;
}

MyString MyString::operator+(const MyString& ms) const
{
    MyString res(*this);
    for (int i = 0; i < ms.lChar.size(); ++i)
    {
        res.lChar.push_back(ms.lChar[i]);
    }
    return res;
}

MyString operator+(const char* s, const MyString& ms)
{
    MyString res(s);
    return res + ms;
}

std::ostream& operator<<(std::ostream& os, const MyString& ms)
{
    for (int i = 0; i < ms.lChar.size(); ++i)
    {
        os << ms.lChar[i];
    }
    return os;
}

SLList<MyString> MyString::Split(const SLList<char>& arrChar, bool removeEmpty) const
{
    SLList<MyString> res;
    MyString current;
    int n = lChar.size();
    int m = arrChar.size();

    for (int i = 0; i < n; ++i)
    {
        char c = lChar[i];
        bool isDelim = false;
        for (int j = 0; j < m; ++j)
        {
            if (c == arrChar[j])
            {
                isDelim = true;
                break;
            }
        }

        if (isDelim)
        {
            if (!removeEmpty || current.lChar.size() > 0)
            {
                res.push_back(current);
            }
            current.lChar.clear();
        }
        else
        {
            current.lChar.push_back(c);
        }
    }

    if (!removeEmpty || current.lChar.size() > 0)
    {
        res.push_back(current);
    }

    return res;
}