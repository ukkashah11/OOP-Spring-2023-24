//using functions to implement exception handling
#include "iostream"
using namespace std;
int throw_func(int x){
    if(x==50)throw 2;
    throw 0;
}
void exblock(int x){
    if(x==50)
    {
        try
        {
            throw_func(x); //use the throw func inside the function that has the try-catch block
        }
        catch(int& e)
        {
            cout<<x<<" is the int thrown"<< '\n';
        }
        
    }
}
int main()
{
    exblock(50);
}
