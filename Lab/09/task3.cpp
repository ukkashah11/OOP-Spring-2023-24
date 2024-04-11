#include "iostream"
using namespace std;
class Employee{
    int ID;
    string name;
    public:
    Employee(int id, string n): ID(id), name(n){}
    virtual double calculatePay() const = 0;
    virtual void displayDetails() const{
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
    };
    string getName() const{
        return name;
    }
    int getID() const{
        return ID;
    }
};
class PartTimeEmployee : public Employee{
float hourlywage;
int hours;
public:
PartTimeEmployee(float hw, int h, int id, string n):hourlywage(hw), hours(h), Employee(id,n){}
double calculatePay()const{
    return hourlywage*hours;
}
void displayDetails()const{
    cout<<"Name: "<<getName()<<endl;
    cout<<"ID: "<<getID()<<endl;
    cout<<"Type: Part-Time"<<endl;
    cout<<"Hourly Wage: "<<hourlywage<<endl;
    cout<<"Hours worked: "<<hours<<endl;
    cout<<"Total Pay: "<<calculatePay()<<endl;
}
};
class FullTimeEmployee : public Employee{
float wage;
public:
FullTimeEmployee(float w,int id, string n):wage(w),Employee(id,n){}
double calculatePay()const{
    return wage;
}
void displayDetails()const{
    cout<<"Name: "<<getName()<<endl;
    cout<<"ID: "<<getID()<<endl;
    cout<<"Type: Full-Time"<<endl;
    cout<<"Wage: "<<wage<<endl;
    cout<<"Total Pay: "<<calculatePay()<<endl;
}
};
int main(){
    Employee* employee = new PartTimeEmployee(15, 40, 101, "AAA");
    employee->displayDetails();
    employee = new FullTimeEmployee(800, 102, "BBB");
    employee->displayDetails();
    delete employee;
    return 0;
}