#include <iostream>
#include "frac.h" 
using namespace std;

int main() {
    cout << "=== 1. TEST KHỞI TẠO VÀ NHẬP/XUẤT STREAM ===" << endl;
    Frac f1;      
    Frac f2(3);   
    Frac f3;

    cout << "Nhap phan so f3: " << endl;
    cin >> f3;

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    cout << "\n=== 2. TEST TOÁN TỬ SỐ HỌC (+, -, *, /) ===" << endl;
    Frac f_tong = f2 + f3;
    Frac f_hieu = f2 - f3;
    Frac f_tich = f2 * f3;
    Frac f_thuong = f2 / f3;

    cout << f2 << " + " << f3 << " = " << f_tong << endl;
    cout << f2 << " - " << f3 << " = " << f_hieu << endl;
    cout << f2 << " * " << f3 << " = " << f_tich << endl;
    cout << f2 << " / " << f3 << " = " << f_thuong << endl;

    cout << "\n=== 3. TEST TOÁN TỬ SO SÁNH (>, <, ==, >=, <=, !=) ===" << endl;
    cout << f2 << " > "  << f3 << " : " << (f2 > f3 ? "Dung" : "Sai") << endl;
    cout << f2 << " < "  << f3 << " : " << (f2 < f3 ? "Dung" : "Sai") << endl;
    cout << f2 << " == " << f3 << " : " << (f2 == f3 ? "Dung" : "Sai") << endl;
    cout << f2 << " >= " << f3 << " : " << (f2 >= f3 ? "Dung" : "Sai") << endl;
    cout << f2 << " <= " << f3 << " : " << (f2 <= f3 ? "Dung" : "Sai") << endl;
    cout << f2 << " != " << f3 << " : " << (f2 != f3 ? "Dung" : "Sai") << endl;

    cout << "\n=== 4. TEST TOÁN TỬ GÁN PHỨC HỢP (=, +=, *=) ===" << endl;
    Frac f4 = f3; // Test operator=
    cout << "f4 khoi tao tu f3 = " << f4 << endl;

    f4 += f2; // Test operator+=
    cout << "f4 sau khi += f2 : " << f4 << endl;

    f4 *= f2; // Test operator*=
    cout << "f4 sau khi *= f2 : " << f4 << endl;

    return 0;
}