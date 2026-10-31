#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
    int n;
    vector<int> a;
public: 
    Array();

    void input();
    void output();

    void set_size(int a ) ;
    int get_size();

    void set_ele(int b, int position);
    int get_ele(int position);

    int find(int x);
    void sort(char option);
};