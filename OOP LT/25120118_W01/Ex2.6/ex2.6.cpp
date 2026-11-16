#include "ex2.6.h"

int main() {
    Array arr;
    arr.input();
    cout << "Mang sau khi nhap: ";
    arr.output();

    cout <<"Size cua mang: " << arr.get_size();

    if (arr.get_size() > 0) {
        cout << "Phan tu tai vi tri index 0: " << arr.get_ele(0) << endl;
        
        cout << "Cap nhat phan tu tai index 0 thanh 99..." << endl;
        arr.set_ele(99, 0);
        
        cout << "Mang sau khi cap nhat: ";
        arr.output();
        cout << endl;
    }
    cout << endl;

    int x = 0;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int idx = arr.find(x);
    if (idx != -1) {
        cout << "Tim thay " << x << " tai vi tri index: " << idx << endl;
    } else {
        cout << "Khong tim thay " << x << " trong mang." << endl;
    }
    cout << endl;

    char c;
    cout <<"Nhap option sap xep mang: (A: tang dan; B: giam dan)"; 
    cin >> c;
    arr.sort(c);
    cout <<"Sau khi sap xep: ";
    arr.output();
    cout << endl;

}