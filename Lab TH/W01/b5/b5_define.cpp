#include "b5.h"

int MangSoNguyen::ChuanHoa(int x) {
    if (x < 0) return 0;
    if (x > MAX_VAL) return MAX_VAL;
    return x;
}

MangSoNguyen::MangSoNguyen() {
    n = 0;
}

MangSoNguyen::MangSoNguyen(int x) {
    n = ChuanHoa(x);
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

MangSoNguyen::MangSoNguyen(const int arr[], int x) {
    n = ChuanHoa(x);
    if (arr != nullptr && n > 0) {
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }
    } else {
        n = 0;
    }
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& x) {
    n = x.n;
    for (int i = 0; i < n; i++) {
        a[i] = x.a[i];
    }
}


void MangSoNguyen::Xuat() {
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}