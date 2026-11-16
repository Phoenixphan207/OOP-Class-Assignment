#pragma once

#include <iostream>
using namespace std;

bool tang(int a, int b);
bool giam(int a, int b);
bool *compare(int a , int b);

void sort(int a[] , int n, bool (*cmp) (int,int));
void print(int a[], int n);