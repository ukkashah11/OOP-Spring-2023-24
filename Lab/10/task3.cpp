#include <iostream>
using namespace std;
class shape{
    float area = 15;
    public:
    shape operator +(const shape& b){
        shape a;
        a.area = area + b.area;
        return a; 
    }
    void print(){
        cout<<area<<endl;
    }
};
int main()
{
	shape shape1, shape2;
    cout<<"Area of shape 1 is: ";
    shape1.print();
    cout<<"Area of shape 2 is: ";
    shape2.print();
    shape shape3 = shape1+shape2;
    cout<<"Area of shape 3 is: ";
    shape3.print();
}
