#include "vd4.h"
#include <iostream>
using namespace std;

int main()
{
    Ngay n1;                    // 1/1/1
    Ngay n2(2, 10, 2014);       // 2/10/2014
    Ngay n3(-10, 16, 2000);     // 10/4/2001
    Ngay n4(1000);              // 27/9/3
    Ngay n5 = n2 + n3;          // 12/2/4016
    Ngay n6 = n1 + 5000;        // 10/10/15
    Ngay n7 = 1234 + n4;        // 16/3/8
    Ngay n8 = 190 + n6 + n7;    // 4/9/25
    Ngay n9 = n8 - n6;          // 25/10/9
    Ngay n10 = 12000 - n9;      // 14/12/23

    if (n10 > n6) 
    {
        n10 = n2 - 1000 + n6;   // 16/10/2026
    }

    cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
    cout << n5 << endl << n6 << endl << n7 << endl << n8 << endl;
    cout << n9 << endl << n10 << endl;

    system("pause");
    return 0;
}