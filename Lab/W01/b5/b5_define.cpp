#include "b5.h"

MangSoNguyen::MangSoNguyen() {
    n = 0;
}

MangSoNguyen::MangSoNguyen(int x) {
    n = x;
}

MangSoNguyen::MangSoNguyen(int arr[], int x) {
    n = x;
    for (int i = 0 ; i < x ; i++) {
        a[i] = arr[i];
    }
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& x) {
    n = x.n;
    for (int i = 0; i < x.n ; i++) {
        a[i] = (x.a)[i];
    }
}
 
void MangSoNguyen::Xuat() {
    if (n == 0) {
        cout << 0 << '\n';
        return ;
    }

    for (int i = 0 ; i <n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
