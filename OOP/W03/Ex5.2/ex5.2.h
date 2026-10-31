#pragma once
#include <iostream> 
using namespace std;
class Client{
private:    
    string name;
    string id;
public: 
    Client(string a, string id1) : name(a) , id(id1) {};
    void display();
};

class Account {
protected: 
    Client cl;
    int num;
    float balance;
public: 
    Account(Client a, int b, float c) : cl(a) , num(b) , balance(c) {};
    float get_balance();

    void deposit(float am);
    void withdraw(float am);
    
    virtual void display();
};

class SavingAccount: public Account {
private: 
    float rate;
public:
    SavingAccount(Client a, int b, float c, float r) 
        : Account(a, b, c), rate(r) {};

    void app_interest();
    void display() override;
};
