#include "ex5.1.h"
using namespace std;

void Address::display() {
    cout << "Street: " << street << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl; 
}

char Student::get_grade() {
    if (gpa >= 9.0 && gpa <= 10.0) {
        return 'A';
    }
    if (gpa >= 8.0 && gpa < 9.0) {
        return 'B';
    }
    if (gpa >= 6.5 && gpa < 8.0) {
        return 'C';
    }
    return 'D';
}

void Student::display() {
    cout << "Name: " << name << endl;
    cout << "MSSV: " << mssv << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Grade: " << (*this).get_grade() << endl;
    cout << "Address: ";
    add.display();

}

Exchange::Exchange(std::string a, int ms, float gpa1, Address b, std::string nuoc, int mon)
    : Student(a, ms, gpa1, b), country(nuoc), month(mon) {}

void Exchange::set_duration(int a) {
    month = a;
}

void Exchange::display() {
    Student::display();
    cout << "Country: " << country << endl;
    cout << "Duration: " << month << endl;

}