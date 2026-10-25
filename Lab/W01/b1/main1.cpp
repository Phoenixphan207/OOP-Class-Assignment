#include <iostream>
#include "b1.h"
using namespace std;

void Create()
{
    Object obj1(5);  
    Object obj2;     
}

Object objGlobal;     

int main()
{
    Object obj1;      
    Create();         
    Object obj2(3);   
    return 0;
}