#include "ex5.2.h"

int main() {
    cout << "=== TEST CLIENT & ACCOUNT ===\n";
    Client c1("Nguyen Van A", "C01");
    Account acc1(c1, 1001, 500.0f);
    acc1.display();
    
    cout << "\n--- Giao dich ---\n";
    acc1.deposit(200.0f);
    acc1.withdraw(150.0f);
    cout << "So du (get_balance): " << acc1.get_balance() << "\n\n";

    cout << "=== TEST SAVING ACCOUNT ===\n";
    Client c2("Tran Thi B", "C02");
    SavingAccount saveAcc(c2, 2002, 1000.0f, 0.05f); // Lai suat 5%
    saveAcc.display();

    cout << "\n--- Cong lai suat ---\n";
    saveAcc.app_interest();
    cout << "\n--- Thong tin sau khi cong lai ---\n";
    saveAcc.display();

    return 0;
}