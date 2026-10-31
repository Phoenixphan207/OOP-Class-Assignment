#include "ex6.1.h"
using namespace std;

int main() {
    cout << "=== KIEM THU LOP ARRAY ===\n";
    Array arr(5);
    arr.set(0, 3);
    arr.set(1, 7);
    arr.set(2, 2);
    arr.display();

    cout << "\n=== KIEM THU LOP HISTOGRAMARRAY ===\n";
    HistogramArray hArr(6, 5); 
    
    hArr.set(0, 1);
    hArr.set(1, 3);
    hArr.set(2, 1);
    hArr.set(3, 4);
    hArr.set(4, 1);
    hArr.set(5, 3);

    cout << "Mang ban dau:\n";
    hArr.display();
    hArr.display_histogram();

    cout << "\n--- Thay doi gia tri tai vi tri index = 2 (tu 1 sang 4) ---\n";
    hArr.set(2, 4);

    cout << "Mang sau khi thay doi:\n";
    hArr.display();
    hArr.display_histogram();

    return 0;
}