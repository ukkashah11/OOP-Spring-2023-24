#include<iostream>
#include<string>
using namespace std;
class Complex{
  int a, i;
  public:
  friend void set(Complex* a, int x, int y);
  friend int sum(Complex a, Complex b);
};
void set(Complex* a, int x, int y){ //use ptr to modify values
  a->a = x;
  a->i = y;
}
int sum(Complex a, Complex b){
  return a.i + b.i;
}
int main(){
  Complex c1, c2;
  set(&c1, 1, 2);
  set(&c2, 3, 4);
  cout<<sum(c1,c2);
  return 0;
}
