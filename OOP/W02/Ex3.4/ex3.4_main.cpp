#include "array_2.h"

int main() {
    Array<int> a1;
    a1.Xuat();

    Array<int> a2(5);
    a2.Xuat();

    int arrInt[] = {10, 20, 30};
    Array<int> a3(arrInt, 3);
    a3.Xuat();

    Array<int> a4(a3);
    a4.Xuat();

    double arrDouble[] = {1.5, 2.7, 3.14};
    Array<double> a5(arrDouble, 3);
    a5.Xuat();

    string arrStr[] = {"OP", "C", "P"};
    Array<string> a6(arrStr, 3);
    a6.Xuat();

    return 0;
}