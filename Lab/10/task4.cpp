#include <iostream>
using namespace std;

class Perimeter{
private:
  int length;
  int breadth;
  int perimeter; 
public:
  Perimeter(int length, int breadth) : length(length), breadth(breadth) {}

  friend class PrintClass;  
};

class PrintClass{
public:
  void print(Perimeter perimeter){
    perimeter.perimeter = 2 * (perimeter.length + perimeter.breadth);
    cout << "Perimeter: " << perimeter.perimeter << endl;
  }
};

int main(){
  Perimeter a(5, 10);
  PrintClass b;
  b.print(a);
  
}
