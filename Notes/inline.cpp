#include<iostream>
using namespace std;
inline int cube(int s){ //inline funcs eliminate overhead and makes your program faster but overall size of program may increase
  return s*s*s;
}
int main(){
  cout<<"cube of 3 is "<<cube(3)<<endl; /*inlining is a request to compiler, not a command.
                                          Inlining might be ignored if a func is recursive, contains loops, switch statements, contains static vars*/
  return 0;                                        
                                          
}
