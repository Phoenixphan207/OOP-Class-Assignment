#include "array.h"

Array::Array(){
    data = nullptr;
    n = 0;
}

Array::Array(int size){
    if (size <= 0) {
        n = 0;
        data = nullptr;
    }
    else {
        n = size;
        data = new int[size]();
    }
}

Array::Array(const int a[], int length) {
    if (length <= 0) {
        n = 0;
        data = nullptr;
    }
    else {
        n = length;
        data = new int[n];
        for (int i = 0  ;i < n; i++) {
            data[i] = a[i];
        }
    }
}

Array::Array(const Array& a) {
    n = a.n;
    if (n > 0 && a.data != nullptr) {
        data = new int[n];

        for (int i = 0 ; i < n ; i++) {
            data[i] = a.data[i];
        }
    }
    else {
        n = 0;
        data = nullptr;
    }
}

void Array::xuat() {

    for (int i = 0 ; i < n ; i++) {
        cout << data[i] << " ";
    }
}   

Array::~Array(){
    delete[] data;
}
