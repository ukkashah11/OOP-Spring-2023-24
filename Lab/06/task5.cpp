#include <iostream>
#define SIZE 6
using namespace std;
class Course{
    static int id;
    string course_code, course_name;
    int cred_hrs;
    public:
    int getCreds()const{
        return cred_hrs;
    }
    string getCode()const{
        return course_code;
    }
    string getName()const{
        return course_name;
    }
    Course(string name, int creds):course_name(name), cred_hrs(creds){
        course_code = std::string(1, course_name[0]) + std::string(1, course_name[1]) + std::to_string(id++);

    }
};
class Student{
    static int id;
    string std_id, std_name;
    Course* enrolled [SIZE];
    public:
    string getName()const{
        return std_name;
    }
    string getId() const{
        return std_id;
    }
    Student(string name): std_name(name){
        std_id = std_name[0]+to_string(id++); //Student ID init to First letter of name + auto incremented cnt
        for(int i=0; i<SIZE; i++){
            enrolled[i]=nullptr;
        }
    }
    void enroll(Course* obj){
        for(int i=0; i<SIZE; i++){
            if(enrolled[i] == nullptr){
                enrolled[i] = obj;
                break;
            }
        }
    }
    void drop(Course* obj){
        for(int i=0; i<SIZE; i++){
            if(enrolled[i] == obj){
                enrolled[i] = nullptr;
            }
        }
    }
    int getTotalCreditHours() const{
        int creds = 0;
        for(int i=0; i<SIZE; i++){
            if(enrolled[i]!=nullptr){
                creds += enrolled[i]->getCreds();
            }
        }
        return creds;
    }
    void printEnrolledCourses(){
        cout<<"Enrolled Courses\n";
        for(int i=0; i<SIZE; i++){
            if(enrolled[i]!=nullptr){
                cout<<"Course Name: "<<enrolled[i]->getName()<<endl;
                cout<<"Course Code: "<<enrolled[i]->getCode()<<endl;
                cout<<"Credit Hours: "<<enrolled[i]->getCreds()<<endl;
                cout<<"\n";
            }
        }
    }
};
int Student::id;
int Course::id;
int main(){
    Student std("SYED UKKASHAH");
    Course c1("OBJECT ORIENTED PROGRAMMING", 3);
    Course c2("EXPOSITORY WRITING", 3);
    Course c3("ISLAMIC STUDIES", 1);
    Course c4("CALCULUS", 2);
    Course c5("OBJECT ORIENTED PROGRAMMING", 3);
    Course c6("HISTORY", 1);
    cout<<"Student Name: "<<std.getName()<<endl;
    cout<<"Student ID: "<<std.getId()<<endl;
    std.enroll(&c1);
    std.enroll(&c2);
    std.enroll(&c3);
    std.enroll(&c4);
    std.enroll(&c5);
    std.enroll(&c6);
    std.printEnrolledCourses();
    cout<<"Total Credit Hours: "<<std.getTotalCreditHours();
    std.drop(&c4);
    std.drop(&c2);
    cout<<"\n";
    std.printEnrolledCourses();
    cout<<"Total Credit Hours: "<<std.getTotalCreditHours();
    return 0;
}