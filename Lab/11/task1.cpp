#include "iostream"
using namespace std;
template <typename T>
class convert{
    protected:
    T val1, val2;
    public:
    virtual T compute() = 0;
    convert(T v1):val1(v1){}
};
class l_to_g : public convert<float>
{
    public:
    l_to_g(float v1):convert(v1){}
    float compute(){val2 = (val1 - 32) * 5.0 / 9.0; return val2;}

};
class f_to_c : public convert<float>
{
    public:
    f_to_c(float v1):convert(v1){}
    float compute(){val2 = val1+32; return val2;}
};
int main()
{
    f_to_c farToCel(70);
    l_to_g LitT0Gal(4);
    convert<float>* baseptr = &farToCel;
    cout<<"70 Farenheit -> "<<baseptr->compute()<<" Celsius"<<endl;
    baseptr = &LitT0Gal;
    cout<<"4 Liters -> "<<baseptr->compute()<<" Gallons"<<endl;
    return 0;
}
