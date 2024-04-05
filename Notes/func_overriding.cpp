#include<iostream>
#include<string>
using namespace std;
class A{
  public:
  virtual void display(){
    cout<<"Base class A display func"<<endl;
  }
  void hello(){
    cout<< "Hello" << endl;
  }
};
class B : public A{
  public:
  void display(){
    cout<<"Derived class B display func"<<endl;
  }
  void hello(){
    cout<<"Greetings"<<endl;
  }
};
int main(){
  A* ptr; 
  B b;
  ptr = &b; //when a parent class ptr is assigned to the address of the derived class object, it is called downcasting
  ptr->hello(); //base class func is called since hello in derived is not overrided (virtual keyword not used)
  ptr->display(); /*derived class func is called since display has been overrided (virtual keyword used).
                    (DYNAMIC/RUN TIME POLYMORPHISM, LATE BINDING)*/
                    
  return 0;
}
