#include "ex2.6.h"

Array::Array() {
    vector<int> c;
    a = c;
    n = 0;
}

void Array::input() {
    cout << "Nhap array size: ";
    cin >> n;
    while (n <= 0 ) {
        cout << "Nhap lai so > 0: ";
        cin >> n;
    }

    for (int i = 0 ; i < n ; i++) {
        cout << "Nhap phan tu thu :" << i + 1 << endl;
        int t =0 ;
        cin >> t;
        a.push_back(t);
    }
}

void Array::output() {
    for (int i = 0 ; i < n ; i++) {
        cout << a[i] << ' ' ;
    }
}

void Array::set_size(int a) {
    n = a;
}
int Array::get_size() {
    return n;
}

void Array::set_ele(int b, int position) {
    if (position > n  || position < 0) {
        cout << "ERROR";
        return;
    }

    a[position] = b;
}

int Array::get_ele(int position) {
    if (position > n  || position < 0) {
        cout << "ERROR";
        exit(-1);
    }
    return a[position];
}

int Array::find(int x) {
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

void Array::sort(char option) { // option 'A' : sort increasing; option 'B': sort decreasing
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            if (option == 'A') {
                if (a[i] > a[j])
                    swap(a[i] , a[j]);
            }
            else {
                if (a[i] < a[j])
                    swap(a[i] , a[j]);
            }
        }
    }
}