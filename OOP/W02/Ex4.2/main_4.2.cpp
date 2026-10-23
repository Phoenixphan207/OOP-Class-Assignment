#include <iostream>
#include "array_4.2.h"

using namespace std;

int main() {
    cout << "================ 1. TEST INPUT & OUTPUT (>>, <<) ================" << endl;
    Array a1(3); 
    cout << "Nhap 3 phan tu cho mang a1:" << endl;
    cin >> a1;
    cout << "Mang a1 vua nhap: " << a1 << endl;

    cout << "\n================ 2. TEST CONCATENATION (+) ================" << endl;
    int arr2[] = {4, 5};
    Array a2(arr2, 2); 
    cout << "Mang a2: " << a2 << endl;

    Array a3 = a1 + a2; 
    cout << "Mang a3 (a1 + a2): " << a3 << endl;

    cout << "\n================ 3. TEST ASSIGNMENT (=, +=) ================" << endl;
    Array a4;
    a4 = a1; 
    cout << "Mang a4 (sau khi gán a4 = a1): " << a4 << endl;

    a1 += a2; 
    cout << "Mang a1 (sau khi a1 += a2): " << a1 << endl;

    cout << "\n================ 4. TEST INDEXER ([]) ================" << endl;
    cout << "Phan tu a1[0] hien tai: " << a1[0] << endl;
    a1[0] = 999; 
    cout << "Mang a1 sau khi doi a1[0] = 999: " << a1 << endl;

    cout << "\n================ 5. TEST TYPE-CAST (int*) ================" << endl;
    int* raw_data = (int*)a1; 
    
    cout << "In cac phan tu qua con tro int* nguyen thuy:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << raw_data[i] << " ";
    }
    cout << endl;

    return 0;
}