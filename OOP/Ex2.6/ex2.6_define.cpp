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

void Array::set_ele(int a) {
    
}