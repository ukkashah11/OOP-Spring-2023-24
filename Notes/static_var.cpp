#include<iostream>
using namespace std;
class Employee{
  static int count;
  string name, id;
  public:
  void getData(){
    cout<<"The ID of this Employee is: "<<id<<endl;
  }
  Employee(string name): name(name){
    count++;
    int i=0;
    bool flag = true;
    while (flag)
    {
      if(name[i] ==' '){
            id = string(1,name[0])+string(1,name[i+1])+to_string(count); //str concat using +, string constructor used: string(num of times a is repeated, char a)
            flag = false;
      }
      if(name[i]=='\0'){
        id=string(1,name[0])+to_string(count);
        flag = false;
      }
      i++;
    }
    }
    static int getCount(){
      cout<<"The value of count is: "<<count<<endl;
    }
  };
int Employee::count;/*Default value=0 
                     When you declare a static member variable like static int count; inside a class, 
                     you're telling the compiler about the existence of this variable, 
                     but you're not actually defining it—i.e., you're not allocating storage for it. 
                     The scope resolution operator is used outside the class definition
                     to define and allocate storage for this static member. 
                     This definition is crucial for the program to link successfully, 
                     as it resolves the storage location for the static variable.
                    */
int main(){
  Employee emp1("Syed Ukkashah");
  emp1.getData();
  Employee::getCount(); //This is how we call static methods in main
  Employee emp2("Hashir Naimatullah");
  emp2.getData();
  Employee::getCount();
  Employee  emp3("Eizaan");
  emp3.getData();
  Employee::getCount();
}
