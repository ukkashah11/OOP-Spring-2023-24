#include<iostream>
#include<string>
using namespace std;
class Complex{
  int i;
  public:
  friend void set(Complex* a, int y); //use ptr if values have to be modified
  friend int sum(Complex a, Complex b); 
  void display(){
    cout<<"Sum is "<<i<<endl;
  }
  friend void call(); 
};
void call(){ 
  Complex w;
  w.i = 5; //since this is a friend function, Complex obj can have it's private member vars modified without a setter function 
  w.display();
}
void set(Complex* a,int y){
  a->i = y;
}
int sum(Complex a, Complex b){
  return a.i + b.i;
}
int main(){
  Complex c1, c2;
  set(&c1,2);
  set(&c2,4);
  cout<<sum(c1,c2)<<endl;
  call();
  return 0;
}

