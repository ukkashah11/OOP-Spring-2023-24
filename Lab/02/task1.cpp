
#include <iostream>  
using namespace std;
void swapNumbers(int *a, int *b, int count) {  
    if (count == 0) {  
        return;  
    } else {  
        int temp = *a;  
        *a = *b;  
        *b = temp;  
        swapNumbers(a, b, count - 1);  
    }  
}  
int main() {  
    int x,y,cnt;
    cout<<"Enter value of x: ";
    cin>>x;
    cout<<"Enter value of y: ";
    cin>>y;
    cout<<"Enter the number of times the values must be swapped recursively: ";
    cin>>cnt;  
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;   
    swapNumbers(&x,&y,cnt);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;  
    return 0;  
}