#pragma once 
#include <iostream>
#include <ostream>
using namespace std;

class Array{
private:
    int *data;
    int n;
public:
    Array(): data(nullptr) , n(0) {};
    Array(int a[], int size);
    Array(int size);
    Array(const Array& a1);
    
    Array operator+(const Array& a1);
    Array& operator=(const Array& a1);
    Array& operator+=(const Array& a1);

    int& operator[](int ind);
    operator int*() const;

    friend ostream& operator<<(ostream& os , const Array& a1);
    friend istream& operator>>(istream& is ,  Array& a1);
    
    ~Array();
};
