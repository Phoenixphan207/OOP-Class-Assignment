#pragma once

#include <iostream>

using namespace std;

class Student {
private: 
    string name;
    float toan;
    float ly;
    float hoa;
public: 
    Student() : name("") , toan(0.0) , ly(0.0), hoa(0.0) {};
    Student(string s , float a ,float b, float c);

    void input();
    void output();
    
    void set_name(string s);
    string get_name();
    void set_toan(float a);
    float get_toan();
    void set_ly(float a);
    float get_ly();
    void set_hoa(float a);
    float get_hoa();

    float gpa();
    char grade();
};