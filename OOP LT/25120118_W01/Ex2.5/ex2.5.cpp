#include "ex2.5.h"

int main() {
    Student a;
    a.input();
    a.output();

    Student tmp = a;
    
    a.set_name("Andrew Phoenix");
    a.set_toan(10.0);
    a.set_hoa(7.0);
    a.set_ly(9.5);

    cout << "Hoc sinh sau khi set Name == Phat; set Toan = 10.0; set Ly = 9.5; set Hoa = 7.0: " << endl;
    a.output();

    cout <<"Hoc sinh ban dau co gpa = " << tmp.gpa() << " , Hang: " << tmp.grade();

}