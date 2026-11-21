#pragma once 
#include <iostream>
#include <cstring>
#include "b4_sllist.h"

class MyString
{
private:
    SLList<char> lChar;

public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& ms);
    ~MyString();

    MyString& operator=(const MyString& ms);
    MyString operator+(const MyString& ms) const;
    friend MyString operator+(const char* s, const MyString& ms);
    friend std::ostream& operator<<(std::ostream& os, const MyString& ms);

    SLList<MyString> Split(const SLList<char>& arrChar, bool removeEmpty = false) const;
};