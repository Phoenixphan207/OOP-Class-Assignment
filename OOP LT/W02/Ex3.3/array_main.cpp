#include "array.h"

int main() {
    Array a1;
    a1.xuat();
    cout <<endl;
    Array a2(5);
    a2.xuat();
    cout << endl;
    int a[4] = {1,2,5,4};
    Array a3(a , 4);
    cout << endl;
    Array a4(a3);
    a4.xuat();
}