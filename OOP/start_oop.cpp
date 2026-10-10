#include <iostream>

using namespace std;

class abstract_employ {
    virtual void Ask_for_promotion() = 0;
};

class Employ:abstract_employ { // lớp Employ kế thừa lớp abstract_employ
private:
    string company;
protected:
    string name;
    int age;
public:
    void set_name( string n) {  //setter
        name = n;
    }
    string get_name() {  //getter
        return name;
    }
    void set_age(int a) {
        age = a;
    }
    int get_age(){
        return age;
    }
    // vd kĩ thuật setter - getter của encapsulation -> cho phép đọc đc object  trong private
    void introduce() {
        cout << "Name: " << name << endl;
        cout << "COmpany: "  << company << endl;
        cout << "Age :" << age  << endl;
    }

    Employ(string n , int a , string c) {
        name = n;
        age = a;
        company = c;
    }

    void Ask_for_promotion() {
        if (age > 30) cout <<" YES";
        else cout << "NO";
    }
    
    virtual void Work() { // từ khóa virtual -> kêu complier check xem phiên bản MỚI nhất có xuất hiện trong các class kế thừa ko(tùy vào object đang call)
        cout << name << " is waving" << endl;
    }
};

class Developer : public Employ {   // nếu ko khai báo kế thừa = cách này mà khai báo kiểu class Developer : Employ -> kế thừa private
    // -> mọi hàm đc kế thừa đều auto kiểu private 
public: 
    string program;
    Developer(string Name, int age , string company , string fav_program)
        : Employ(Name, age, company) {
        program = fav_program;
    }
    
    void fix_bug(){
        cout << get_name() << " is "<< get_age() << "years old";
    }

    void Work() {   // ví dụ về tính đa hình Work có nhiều hình thái khác nhau
        cout << name << " is processing" <<program << endl;
    }
};

class Teacher : public Employ{
public:
    string Sub;
    Teacher(string name , int age , string company, string sub) 
    : Employ(name , age , company) {
        Sub = sub;
    }

    void Work() {
        cout << name << " is teaching" << Sub << endl;
    }
};

int main() {
    Employ e("phat" , 31 , "phoenix");
    
    // e1.introduce();

    // e1.set_name("Phoenix");
    // cout << "New name: " << e1.get_name();
    // e1.Ask_for_promotion();

    Developer d = Developer("phat", 31, "phoenix", "C++");  
    d.introduce();

    d.Work();
    Teacher t = Teacher("phoenix", 22 , "haha" , "math");
    t.Work();

    Employ *e1 = &d;
    Employ *e2 = &t;

    e1->Work();

    return 0 ;
}

/*
4 đặc trưng quan trọng of OOP :

1, Encapsulation : Tính đóng gói 
 - Nhóm dữ liệu , thuộc tính vào trong cùng 1 class 
  + Mục đích : ẩn đi các chi tiết nội bộ , chỉ show ra những thứ cần thiết
** Kĩ thuật setter - getter
2, Abstraction : Tính trừu tượng 
 - Ẩn đi những logic phức tạp vào sâu trong code , chỉ cung cấp giao diện 
 cơ bản cho người dùng 

3, Inheritance : Tính kế thừa 
 - Cho phép class con kế thừa class cha 
  + Mục đích : Tái sử dụng code 
- mọi hàm trong class cha đều có thể gọi đc trong class con 
** nếu class cha có constructor (tự làm) -> class con cx phải tự tạo 

4, Polymorphism : Tính đa hình
 - Cho phép 1 method (void , int,..) có nhiều hình thái (nhiều cách thực hiện) 
 tùy vào object gọi nó 
*/