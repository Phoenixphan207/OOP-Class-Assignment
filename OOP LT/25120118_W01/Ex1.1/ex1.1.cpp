#include "ex1.1.h"

using namespace std;

template <typename T>
void sort_array(T a[] , int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (a[i] > a[j]) 
                swap(a[i],  a[j]);
        }
    }
}

template <typename T>
void print(const T a[] , int n ) {
    for (int i = 0  ;i < n ; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int int_ar[5] = {1, 5, 2, 4, 7};
    sort_array(int_ar , 5);
    cout << "Mang int sau khi sap xep: " ;
    print(int_ar , 5);

    cout << endl;

    float floatArray[4] = {3.14f, 1.41f, 2.71f, 0.57f} ;
    sort_array(floatArray , 4);
    cout << "Mang float sau khi sap xep: ";
    print(floatArray , 4);

    cout << endl;

    char charArray[5] = {'e', 'a', 'c', 'b', 'd'};
    sort_array(charArray, 5);
    std::cout << "Mang char sau khi sap xep: ";
    print(charArray, 5);
}