#include "ex2.4.h"

int main() {
    Fraction a;
    a.input();
    a.output();
    Fraction tmp = a;

    cout << "Tu so: ";
    cout << a.getNum() << endl;
    a.setNum(2);
    cout << "Tu so sau khi set = 2: ";
    cout << a.getNum() << endl;

    cout << "Mau so: ";
    cout << a.getDenom() << endl;
    a.setDenom(5);
    cout << "Mau so sau khi set = 5: ";
    cout << a.getDenom() <<  endl;

    tmp.reduce();
    cout << "Phan so sau khi rut gon: ";
    tmp.output();

    Fraction a_t = tmp;
    tmp.inverse();
    cout << "Phan so nghich dao: ";
    tmp.output();

    Fraction b(5,6);
    cout <<"Tong cua 2 phan so a va 5/6 = ";
    Fraction res = a_t.add(b);
    res.output();

    cout << a_t.compare(b);
    
}