#include "vd1.h"
using namespace std;

int main()
{
    SoPhuc sp1(3, 5);
    SoPhuc sp2 = sp1.operator+(10);
    SoPhuc sp3 = sp1 + 10;
    sp1.operator<<(cout);
    cout << endl;
    sp2.operator<<(cout);
    cout << endl;
    sp3.operator<<(cout);
    cout << endl;
    system("pause");
    return 0;
}