#pragma once

#include <iostream>
#include <string>
using namespace std;

#define MAX_VAL 10000

template <typename T>
class Array{
private:
    T* data;
    int length;
public:
    Array(): data(nullptr), length(0) {};
    Array(int n) {
        if (n <= 0) {
            length = 0;
            data = nullptr;
        }
        else {
            length = n;
            data = new T[n];
        }
    }
    Array(T arr[] , int n) {
        if (n <= 0) {
            length = 0;
            data = nullptr;
        }

        else {
            length = n;
            data = new T[n];
            for (int i = 0 ; i < length; i++) {
                data[i] = arr[i];
            }
        }
    }
    Array(const Array& a1) {
        if (a1.length <= 0 || a1.data == nullptr) {
            length = 0;
            data = nullptr;
        }
        else {
            length = a1.length;
            data = new T[length];
            for (int i = 0 ; i < a1.length; i++) {
                data[i] = a1.data[i];
            }
        }
    }

    void Xuat(){
        if (length == 0 || data == nullptr) {
            cout << "";
        }
        else {
            for (int i = 0 ; i < length; i++) {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
    ~Array() {
        delete[] data;
    }
};