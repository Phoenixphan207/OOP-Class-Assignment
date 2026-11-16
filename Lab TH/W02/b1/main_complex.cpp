#include "complex.h"

int SoPhuc::ssl = 0;
int main()
{
    SoPhuc sp1;
    SoPhuc sp2(5, 10);
    SoPhuc sp3(sp1);
    SoPhuc sp4 = sp2.Cong(sp1);
    std::cout << SoPhuc::SSoLuongSP() << std::endl;  // 4
    {
        SoPhuc sp5;
        SoPhuc sp6 = sp2.Cong(sp4);
    }
    std::cout << sp4.SoLuongSP() << std::endl;       // 1
    std::cout << SoPhuc::SSoLuongSP() << std::endl;  // 4

    system("pause");
}