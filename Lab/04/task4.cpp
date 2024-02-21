#include <iostream>
using namespace std;
class Office{
    public:
    string Location, Furniture[3];
    unsigned short SeatingCapacity;
    Office(string loc="", string f1="", string f2="", string f3 ="", unsigned short seats = 0):
    Location(loc), Furniture({f1,f2,f3}), SeatingCapacity(seats){}
    void show() {
        cout << "Location: " << Location << endl
             << "Seating Capacity: " << SeatingCapacity << endl
             << "Furniture:" << endl;
        for (string furniture : Furniture)
            cout << furniture << endl;
        cout << endl;
    }
};
int main(){
    Office o1;
    Office o2("Karachi", "Couch", "Work Desk", "Lamp", 3);
    Office o3("Lahore", "Table", "Chair", "Closet", 2);
    o1.show();
    o2.show();
    o3.show();

}