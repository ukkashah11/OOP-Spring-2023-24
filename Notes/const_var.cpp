#include<iostream>
using namespace std;
/*void f(const int i){
  i++; //this will give error as the parameter is a const int that is unchangeable
}*/
class test{
  const int i; //it is a const data member in every object
  public:
  mutable int j; /*mutable keyword is used with member variables of class, which we want
                 to change even if the object is of const type. Hence, mutable data
                 members of a const objects can be modified.*/
  int a;
  test(int x): i(x){} //i can only be init through member init
  int getI() const{ //a const member func never modifies data members in an obj, this is why it is considered good practice to keep getters const
    return i;
  }
  int setJ(int J) const{ //even though the func is const, it still modified j since int j is mutable
    j = J;
  }
};
int main(){
  const int a=1; //const vars must be init when they are declared
  // a=3; //they can't be changed (gives error)
  const int* p = &a; //pointer points to a const var
  cout<<*p<<endl; 
  int x=2;
  int* const w = &x; //const pointer that point to an int
  // w = &a; //const ptr can't point to a different address (gives error)
  cout<<*w<<endl;
  test t1(5);
 // t1.i = 4; //throws error as i is a const int class data member
 cout<<t1.getI()<<endl;
 const test t2(4); //since this is a const obj, it's data members will never be changed during it's lifetime
 //t2.a = 3; //even though a is non-static, it can't be changed since the obj is const (gives error)
 t2.j = 10; // since int j is mutable, it can be modified from main even if it belongs to a const obj
}
