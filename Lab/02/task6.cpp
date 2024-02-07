#include <iostream>
using namespace std;
int calculateGCD(int x, int y){ //Euclid's algortihm implemented. It states that if a>b, GCD(a,b) = GCD(b,a%b). Base Case: GCD(a,0) = a
    if(y==0){
        return x;
    }
    else{
        return calculateGCD(y,x%y);
    }
}
int calculateLCM(int x, int y){
    static int multiple = 0;
    /* Increments multiple by adding max value to it */
    multiple += y;
    /*
     * Base condition of recursion
     * If found a common multiple then return the multiple.
     */
    if((multiple % x == 0) && (multiple % y == 0))
    {
        return multiple;
    }
    else 
    {
        return calculateLCM(x, y);
    }
}
int main(){
    int a,b;
    cout<<"Enter 1st num: ";
    cin>>a;
    cout<<"Enter 2nd num: ";
    cin>>b;
    if(b>a){ //ensuring a>b
        int temp = a;
        a=b;
        b=temp;
    }
    cout<<"GCD of "<<a<< " & "<<b<<" is "<<calculateGCD(a,b)<<endl;
    cout<<"LCM of "<<a<< " & "<<b<<" is "<<calculateLCM(a,b)<<endl;
    return 0;
}