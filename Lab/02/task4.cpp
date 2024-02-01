#include <iostream>  
#include <string>
#include <limits>
using namespace std;
struct Register{
    int courseId;
    string courseName;
};
struct Student: Register{
   int studentId;
   string firstName,lastName,cellNo,email;
};
void displayDetails(Student stds [5]){
    for(int i=0; i<5; i++){
        cout<<"Student Cell: "<<endl;
        cout<<stds->cellNo<<endl;
        cout<<"Student ID: "<<endl;
        cout<<stds->studentId<<endl;
        cout<<"Student Name: "<<endl;
        cout<<stds->firstName;
        cout<<" "<<stds->lastName<<endl;
        cout<<"Student Email: "<<endl;
        cout<<stds->email<<endl;
        cout<<"Course ID: "<<endl;
        cout<<stds->courseId<<endl;
        cout<<"Course Name: "<<endl;
        cout<<stds->courseName<<endl;
    }
}
int main(){
    Student students[5];
    cout<<"Enter Student Details:"<<endl;
    for(int i=0; i<5; i++){
        cout<<"Student "<<i+1<<endl;
        cout<<"Student ID: ";
        cin>>students[i].studentId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"First Name: ";
        getline(cin,students[i].firstName);
        cout<<"Last Name: ";
        getline(cin,students[i].lastName);
        cout<<"Cell No: ";
        getline(cin,students[i].cellNo);
        cout<<"Email: ";
        getline(cin,students[i].email);
        cout<<"Course ID: ";
        cin>>students[i].courseId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Course Name: ";
        getline(cin,students[i].courseName);
    }
    displayDetails(students);
}
