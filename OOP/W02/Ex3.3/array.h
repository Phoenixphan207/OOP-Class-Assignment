#pragma once

#include <iostream>
using namespace std;

#define MAX_VAL 10000

class Array{
private:
    int *data;
    int n;
public:
    Array();
    Array(int size);
    Array(const int a[], int length);
    Array(const Array& a);

    ~Array();
    void xuat();
};