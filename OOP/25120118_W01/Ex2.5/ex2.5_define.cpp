#include "ex2.5.h"

Student::Student(string s , float a , float b, float c) {
    name = s;
    toan = a;
    ly = b;
    hoa = c;
}

void Student::input(){
    cout << "Nhap ho va ten: ";
    
    getline(cin , name);

    cout << "Nhap diem mon Toan: ";
    cin >> toan;
    cout << "Nhap diem mon Ly: ";
    cin >> ly;
    cout << "Nhap diem mon Hoa: ";
    cin >> hoa;

    while (toan * ly * hoa <= 0) {
        cout << "ERROR, nhap lai diem 3 mon: ";
        cin >> toan >> ly >> hoa;
    }
}

void Student::output() {
    cout << "Ho va ten : " << name << '\n';
    cout << "Diem mon Toan: " << toan << '\n';
    cout << "Diem mon Ly: " << ly << "\n";
    cout << "Diem mon Hoa: "<< hoa << '\n';
}

void Student::set_name(string s) {
    name = s;
}
string Student::get_name(){
    return name;
}
void Student::set_hoa(float a) {
    hoa = a;
}
float Student::get_hoa(){
    return hoa;
}
void Student::set_toan(float a) {
    toan = a;
}
float Student::get_toan() {
    return toan;
}
void Student::set_ly(float a) {
    ly = a;
}
float Student::get_ly() {
    return ly;
}

float Student::gpa() {
    return 1.0*((this->get_hoa() + this->get_ly() + this->get_toan()) / 3);
}

char Student::grade() {
    float gpa = Student::gpa();
    char c;
    if (gpa >= 9) c = 'A';
    else if (gpa >= 7) c = 'B';
    else if (gpa >= 5) c = 'C';
    else c = 'D';
    return c;
}