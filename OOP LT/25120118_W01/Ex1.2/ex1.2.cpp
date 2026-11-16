#include "ex1.2.h"

using namespace std;

bool tang(int a, int b) {
    return a>b;
}
bool giam(int a, int b) {
    return a < b;
}

void sort(int a[] , int n , bool (*cmp)(int ,int)) {
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (cmp(a[i] , a[j]))   
                swap(a[i] , a[j]);
        }
    }
}

void print(int a[] , int n ) {
    for (int i = 0  ;i < n ; i++) {
        cout << a[i] << " ";
    }
}


int main() {
    int n = 0;
    cout <<"Nhap so luong phan tu cua mang: ";
    cin >> n;

    int a[1000];
    for (int i = 0 ; i < n ; i++) {
        cout << "Nhap phan tu thu " << i+1 << " ";
        cin >> a[i];
    }

    int x = 0;
    do {
        cout << "Nhap lua chon sort mang: (1: Tang dan; 2: Giam dan) ";
        cin >> x;
    } while (x != 1 && x != 2);
    
    bool (*cmp)(int ,int) = nullptr;

    if (x == 1) cmp = tang;
    else if (x == 2) cmp = giam;
    
    sort(a , n , cmp);
    cout << "Sau khi sap xep: " << endl;
    print(a , n);
}