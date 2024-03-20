#include <iostream>
using namespace std;
class Employee{
    static int nextEmployeeID;
    const float MAX_SALARY;
    string name;
    float SALARY;
    public:
    static int generateEmployeeID(){
        return nextEmployeeID;
    }
    Employee(const int max, string n):MAX_SALARY(max), name(n){nextEmployeeID++;}
    void setSalary(const int salary){
        if(salary>MAX_SALARY){
            SALARY = MAX_SALARY;
        }
        else{
            SALARY = salary;
            cout<<"Employee salary adjusted"<<endl;
        }
    }
    void displayEmployeeInfo(){
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee ID: "<<generateEmployeeID()<<endl;
        cout<<"Employee Salary: "<<SALARY<<endl;
    }
};
int Employee::nextEmployeeID;
int main(){
    Employee e(1500,"Syed Ukkashah");
    e.setSalary(800);
    e.displayEmployeeInfo();
    e.setSalary(2000);
    e.displayEmployeeInfo();
    return 0;
}