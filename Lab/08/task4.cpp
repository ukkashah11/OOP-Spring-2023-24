#include "iostream"
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(string n, int a):name(n), age(a){}

};
class Student: virtual public Person{
    public:
    static int id;
    int std_id;
    char grade; 
    Student(char g , string n, int a ):grade(g), Person(n,a){id++;std_id = id;}
};
class Teacher : virtual public Person{
    public:
    string subject;
    int room_num;
    Teacher(string s, int room, string n, int a):subject(s), room_num(room), Person(n,a){}
};
class GraduateStudent: public Student, public Teacher{
    public:
    GraduateStudent(char g , string n, int a, string s, int room): Person(n,a), Student(g,n,a), Teacher(s,room,n,a){}
    void display(){
        cout<<"Graduate Student details\nStudent name: "<<name
        <<"\nAge: "<<age
        <<"\nStudent ID: "<<std_id
        <<"\nGrade: "<<grade
        <<"\nTA Details\nSubject: "<<subject
        <<"\nRoom number: "<<room_num<<endl;
    }
};
int Student::id;
int main(){
    GraduateStudent grad_std('A', "Syed Ukkashah", 20, "OOP", 33);
    grad_std.display();
    return 0;
}