#include "iostream"
using namespace std;
class Example {
int a, b;
public:
Example(int x, int y) {
a = x;
b = y;
cout << "\nIm Constructor";
}
Example(const Example &obj) {
a = obj.a;
b = obj.b;
cout << "\nIm Copy Constructor";
}
void Display() {
cout << "\nValues :" << a << "\t" << b;
}
};
int main() {
Example Object(10, 20);
Example Object2 = Object; //to prohibit copying of objects, we can make the copy constructor private
Object.Display();
Object2.Display();
}