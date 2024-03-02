/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
using namespace std;
class Office{
    public:
    string Location, *Furniture;
    unsigned short SeatingCapacity;
    Office(string loc="", unsigned short seats = 0, int size=3):
    Location(loc), Furniture(new string[size]), SeatingCapacity(seats){}
    ~Office(){
        delete[] Furniture;
        cout<<"furniture deleted"<<endl;
    }
};
int main(){
    Office *o1 = new Office("Karachi",3, 3);
    delete o1;
    return 0;
}