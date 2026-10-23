#include "array_4.2.h"
using namespace std;

ostream& operator<<(ostream& os, const Array& a1) {
    for (int i = 0; i < a1.n; i++) {
        os << a1.data[i] << " ";
    }
    return os;
}
istream& operator>>(istream& is, Array& a1) {
    for (int i = 0; i < a1.n; i++) {
        is >> a1.data[i];
    }
    return is;
}

Array::Array(int a[], int size) {
    if (size <= 0) {
        n = 0;
        data = nullptr;
    } else {
        n = size;
        data = new int[n];
        for (int i = 0; i < size; i++) {
            data[i] = a[i];
        }
    }
}

Array::Array(int size) {
    if (size <= 0) {
        n = 0;
        data = nullptr;
    } else {
        n = size;
        data = new int[n](); 
    }
}

Array::Array(const Array& a1) {
    this->n = a1.n;
    if (a1.n > 0) {
        this->data = new int[a1.n];
        for (int i = 0; i < a1.n; i++) {
            this->data[i] = a1.data[i];
        }
    } else {
        this->data = nullptr;
    }
}

Array::~Array() {
    delete[] data;
    data = nullptr;
}

Array Array::operator+(const Array& a1) {
    Array c(this->n + a1.n);
    
    for (int i = 0; i < this->n; i++) {
        c.data[i] = this->data[i];
    }
    for (int i = 0; i < a1.n; i++) {
        c.data[this->n + i] = a1.data[i]; 
    }
    return c;
}

Array& Array::operator=(const Array& a1) {
    if (this != &a1) { 
        delete[] this->data; 
        
        this->n = a1.n;
        if (a1.n > 0) {
            this->data = new int[a1.n];
            for (int i = 0; i < a1.n; i++) {
                this->data[i] = a1.data[i];
            }
        } else {
            this->data = nullptr;
        }
    }
    return *this;
}

Array& Array::operator+=(const Array& a1) {
    *this = *this + a1;
    return *this;
}

int& Array::operator[](int ind) {
    return this->data[ind];
}


Array::operator int*() const {
    return this->data;
}