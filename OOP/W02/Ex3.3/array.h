#pragma once

#include <iostream>
using namespace std;

#define MAX_VAL 10000

class Array{
private:
    int a[MAX_VAL] = {0};
    int length;
public:
    Array();
    Array(int n);
    Array(int arr[] , int n);
    Array(const Array& a1);

    ~Array() = default;
};