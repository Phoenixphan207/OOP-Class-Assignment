#include "vd2.h"
using namespace std;


int main()
{
    SoPhuc sp1(3, 5);
    SoPhuc sp3 = sp1 + 10;
    sp1.operator<<(cout);
    cout << endl;
    sp3.operator<<(cout);
    cout << endl;
    system("pause");
    return 0;
}