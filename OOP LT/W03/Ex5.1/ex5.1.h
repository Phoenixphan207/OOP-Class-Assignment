#pragma once 

#include <iostream>

class Address{
private: 
    std::string street;
    std::string city;
    std::string state;
public: 
    Address(std::string a, std::string b, std::string c): street(a), city(b) , state(c) {};
    void display();
};

class Student {
protected: 
    std::string name;
    int mssv;
    float gpa;
    Address add;
public:
    Student(std::string n, int ms, float gpa1, Address b): name(n), mssv(ms), gpa(gpa1), add(b){};
    char get_grade();
    virtual void display();
};

class Exchange: public Student {
private:
    std::string country;
    int month;
public: 
    Exchange(std::string a, int ms, float gpa1, Address b, std::string nuoc, int mon);
    void set_duration(int a);
    void display() override;
};