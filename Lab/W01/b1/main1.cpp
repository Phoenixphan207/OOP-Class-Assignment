#include <iostream>
#include "b1.h"
using namespace std;

void Create()
{
    Object obj1(5);  // biến cục bộ hàm Create
    Object obj2;     // biến cục bộ hàm Create
}

Object objGlobal;     // biến toàn cục

int main()
{
    Object obj1;      // biến cục bộ hàm main
    Create();         // gọi hàm Create()
    Object obj2(3);   // biến cục bộ hàm main
    return 0;
}