#include <iostream>
#include "b1.h"
using namespace std;

static int numMax = 0;

Object::Object()
{
    info = 0;
    curNum = ++numMax;
    cout << "Khoi tao (mac dinh) doi tuong " << curNum << endl;
}

Object::Object(int value)
{
    info = value;
    curNum = ++numMax;
    cout << "Khoi tao (co doi so) doi tuong " << curNum << endl;
}

Object::~Object()
{
    cout << "Huy doi tuong " << curNum << endl;
}