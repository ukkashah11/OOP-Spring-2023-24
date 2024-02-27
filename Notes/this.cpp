#include<iostream>
using namespace std;
  class A{
    int x,y;
    public:
    A(int x){
      this->x = x; //this keyword used since local var's name = memeber's name
    }
  };
  class Test{
    int x,y;
    public:
    Test(int x=0, int y=0){
      this->x=x;
      this->y=y;
    }
    Test& setX(int a){  //return the address of the object that calls this function. Syntax: class_name& 
      x=a;
      return *this; 
    }
    Test& setY(int b){ 
      y=b;
      return *this;
    }
  };
  int main(){
    Test obj1;
    obj1.setX(10).setY(20); //setX return address of obj1, which is why setX.(setY) is possible
  }
