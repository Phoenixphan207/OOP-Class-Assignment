#include "b1.h"

using namespace std;

int main()
{
    Ngay n1;                    // 1/1/1
    n1.Xuat();
    cout << endl;
    Ngay n2(2, 10, 2024);       // 2/10/2024
    n2.Xuat();
    cout << endl;
    Ngay n3(-100, 16, 1990);    // 10/7/1991
    n3.Xuat();
    cout << endl;
    Ngay n4(1403);              // 23/11/4
    n4.Xuat();
    cout << endl;
    Ngay n5("12-12-2012");      // 12/12/2012
    n5.Xuat();
    cout << endl;

    return 0;
}