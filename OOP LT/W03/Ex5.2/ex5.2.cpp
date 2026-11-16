#include "ex5.2.h"

void Client::display() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}

float Account::get_balance() {
    return balance;
}

void Account::deposit(float am) {
    if (am > 0) {
        balance += am;
        cout << "Nap: " << am << " | So du: " << balance << "\n";
    }
}

void Account::withdraw(float am) {
    if (am > 0 && am <= balance) {
        balance -= am;
        cout << "Rut: " << am << " | So du: " << balance << "\n";
    } else {
        cout << "Giao dich khong hop le!\n";
    }
}

void Account::display() {
    cl.display();
    cout << "STK: " << num << "\nSo du: " << balance << "\n";
}

void SavingAccount::app_interest() {
    float interest = balance * rate;
        balance += interest;
        cout << "Tien lai: " << interest << " | So du moi: " << balance << "\n";
}

void SavingAccount::display() {
    Account::display();
    cout << "Lai suat: " << rate * 100 << "%\n";
}