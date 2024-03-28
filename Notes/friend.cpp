#include "iostream"
using namespace std;
class A{
    int x = 4;
    friend class Afriend;
};
class B{
    int x = 5;
    friend class Afriend;
};
class Afriend{
    public:
    void printX(A a,B b){
        cout<<"A(x): "<<a.x<<" B(x): "<<b.x<<endl;
    }
};
int main(){
    A a;
    B b;
    Afriend friend_class;
    friend_class.printX(a,b);
    return 0;
}
