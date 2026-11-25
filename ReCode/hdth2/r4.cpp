#include "r4.h"

using namespace std;

SoNguyenLon* SoNguyenLon::ds[100];
int SoNguyenLon::sl = 0;

SoNguyenLon::SoNguyenLon() {
    strcpy(val , "0");
    
    ds[sl++] = this;

}

SoNguyenLon::SoNguyenLon(const char* s) {
    strcpy(val , s);

    ds[sl++] = this;
}

SoNguyenLon::SoNguyenLon(int d, int n) { 
    if (n > 100 || n < 0) {
        cout << "ERROR!";
        exit(-1);
    }
    
    for (int i = 0 ; i < n ; i++) {
        val[i] = d + '0';
    }
    val[n] = '\0';

    ds[sl++] = this;
}

SoNguyenLon SoNguyenLon::Cong(long long num) {
    char s2[30];
    sprintf(s2, "%lld", num); // Hoặc dùng vòng lặp chia 10 nếu không muốn dùng cstdio

    const char* s1 = this->val;
    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;
    int nho = 0, k = 0;
    char rev[200]; // Lưu kết quả bị đảo ngược

    // 2. Cộng từ hàng đơn vị sang trái cho đến khi hết cả 2 số VÀ hết biến nhớ
    while (i >= 0 || j >= 0 || nho > 0) {
        int d1 = (i >= 0) ? (s1[i--] - '0') : 0;
        int d2 = (j >= 0) ? (s2[j--] - '0') : 0;

        int sum = d1 + d2 + nho;
        rev[k++] = (sum % 10) + '0';
        nho = sum / 10;
    }

    // 3. Đảo ngược chuỗi rev để được kết quả xuôi
    char res[200];
    for (int idx = 0; idx < k; idx++) {
        res[idx] = rev[k - 1 - idx];
    }
    res[k] = '\0';

    return SoNguyenLon(res);
}

SoNguyenLon Tru(const SoNguyenLon& a) {
    
}

