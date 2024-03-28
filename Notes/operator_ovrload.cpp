#include "iostream"
using namespace std;
class Number{
    public:
    int n;
    Number(int set_n){
        n=set_n;
    }
    Number operator+(const Number &numA)
    {
        return Number(this->n + numA.n); /*we overload + operator, int n of two Number objects are added, 
                                         and it is init to a new Number obj. 
                                         The new Number obj is returned*/
    }
    bool operator ==(const Number &numA){ //we compare int n of two Number objects
        if(this->n == numA.n)return true;
        else return false;
    }
};
int main(){
    Number a(5);
    Number b(10);
    Number c = a + b;
    cout<<c.n<<endl;
    cout<<(a==c)<<endl;
    Number d(15);
    cout<<(c==d)<<endl;
}
