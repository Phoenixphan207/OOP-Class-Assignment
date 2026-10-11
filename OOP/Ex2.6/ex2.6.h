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

    void set_ele(int a);
    int get_ele(int a);

    int find(int a);
    void sort(char option);
};