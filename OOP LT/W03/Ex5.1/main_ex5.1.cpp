#include "ex5.1.h"
using namespace std;

int main()  {
    Address tmp("nguyen chi thanh " , "daklak", "cali");
    Student a("nguyen duc phat" , 23423412, 9.32, tmp);
    a.display();
    cout << endl;

    Exchange phat("nguyen duc phat" , 23423412, 9.32, tmp , "england", 24);
    phat.display();
    cout << endl;
    phat.set_duration(30);
    phat.display();
}