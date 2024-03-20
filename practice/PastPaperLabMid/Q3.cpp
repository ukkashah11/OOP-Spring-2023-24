#include<iostream>
using namespace std;
class Employee{
    protected:
    string name, joining_date;
    int age;
    public:
    Employee(string n, string d, int a): name(n), joining_date(d), age(a){}
    
};
class Developer:public virtual Employee{
    protected:
    string role;
    public:
    Developer(string n, string d, int a, string r):Employee(n,d,a), role(r){}
};
class Debugger:public virtual Employee{
    protected:
    string role;
    public:
    Debugger(string n, string d, int a, string r):Employee(n,d,a), role(r){}
};
class TeamLead:public Developer, public Debugger{
    string role1;
    string role2;
    public:
    TeamLead(string n, string d, int a, string r1, string r2): Employee(n,d,a),Developer(n,d,a,r1), Debugger(n,d,a,r2), role1(r1), role2(r2){}
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Joining Date: "<<joining_date<<endl;
        cout<<"Role(s): "<<role1<<"/"<<role2<<endl;
    }      
};
int main(){
    TeamLead t("Syed Ukkashah", "21st March, 2024", 20, "backend developer", "manual debugger");
    t.display(); 
    //Scenario implements multi-level inheritance (diamond problem solved by virtual keyword)
    return 0;
}