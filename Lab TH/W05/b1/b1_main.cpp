#include <iostream>
#include "b1.h"

using namespace std;

int main()
{
    const int i = 7;

    A a;

    A::indexOf io = a.GetInfo(i);

    cout << *io << endl;

    *io = 10;

    a.Xuat(cout);

    return 0;
}