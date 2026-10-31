#include "ex1.3.h"

using namespace std;

template <typename T>
bool tang(T a, T b) {
    return a > b;
}

template <typename T>
bool giam(T a , T b) {
    return a < b;
}

template <typename T>
void sort(T a[] , int n , bool (*cmp)(int , int)) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (cmp(a[i], a[j])) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    int int_ar[5] = {2, 5, 8, 3, -2};

    int x = 0;
    do {
        cout << "Nhap lua chon sort mang: (1: Tang dan; 2: Giam dan) ";
        cin >> x;
    } while (x != 1 && x != 2);

    bool (*cmp)(int ,int) = nullptr;
    if (x == 1) cmp = tang;
    else cmp = giam;

    sort(int_ar, 5, cmp);
    cout << "Mang so nguyen sau khi sap xep: " << endl;
    for (int i = 0 ; i < 5 ;i++) cout << int_ar[i] << " ";
    cout << endl;

    float floatArray[4] = {3.14f, 1.41f, 2.71f, 0.57f};
    int y = 0;
    do {
        cout << "Nhap lua chon sort mang: (1: Tang dan; 2: Giam dan) ";
        cin >> y;
    } while (y != 1 && y != 2);

    if (y == 1) cmp =tang;
    else cmp = giam;
    sort(floatArray , 4 ,cmp);
    cout << "Mang so thuc sau khi sap xep: " << endl;
    for (int i = 0 ; i < 4 ;i++) cout << floatArray[i] << " ";


}