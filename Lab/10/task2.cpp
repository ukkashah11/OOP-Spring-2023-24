#include<iostream>
using namespace std;

class OverloadDecrement {
    int num;
public:
    OverloadDecrement(int n) : num(n) {}

    // Prefix decrement operator overload
    OverloadDecrement& operator--() {
        num *= 4;
        return *this;
    }

    // Postfix decrement operator overload
    OverloadDecrement operator--(int) {
        OverloadDecrement temp(num);
        num /= 4;
        return temp;
    }

    void print() {
        cout << num << endl;
    }
};

int main() {
    OverloadDecrement od(5);
    cout << "Prefix decrement: ";
    --od;
    od.print();

    cout << "Postfix decrement: ";
    od--;
    od.print();

    return 0;
}
