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
  ptr = &b; //when a parent class ptr is assigned to the address of the derived class object, it is called upcasting
  ptr->hello(); //base class func is called since hello in base class is not overwritten (virtual keyword not used)
  ptr->display(); /*derived class func is called since display in base class has been overwritten (virtual keyword used).
                    (DYNAMIC/RUN TIME POLYMORPHISM, LATE BINDING)*/
  B* child_ptr;
  child_ptr = (B*) ptr; /*we can explicitly cast the parent ptr that points to the address
                          of the child class obj as a ptr of the child class type. This allows us to
                          init it to a ptr of the child class type. This is known is downcasting*/
  child_ptr->display();
  return 0;
}
