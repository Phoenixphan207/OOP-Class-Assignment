#include "frac_2.h"

int Fraction::count = 0;

int main() {
    Fraction a1;
    Fraction a2("1/2");
    Fraction a3(3, 8);
    Fraction a4(5);
    Fraction a5(a2);

    Fraction::print_number();
}