/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
#include <string>
using namespace std;
class BoardMarker {
private:
    string brand;
    string color;
    bool isRefillable;
    bool inkStatus;
public:
    BoardMarker(string brand, string color, bool isRefillable)
        : brand(brand), color(color), isRefillable(isRefillable), inkStatus(true) {}
    string getBrand() const { return brand; }
    string getColor() const { return color; }
    bool getIsRefillable() const { return isRefillable; }
    bool getInkStatus() const { return inkStatus; }
    void setBrand(const string &b) { brand = b; }
    void setColor(const string &c) { color = c; }
    void setIsRefillable(bool refill) { isRefillable = refill; }
    void setInkStatus(bool status) { inkStatus = status; }
    void write() {
        if (!inkStatus) {
            cout << "Cannot write. The ink has run out." << endl;
        } else {
            cout << "Writing with the " << color << " " << brand << " marker." << endl;
        }
    }
    void refill() {
        if (!isRefillable) {
            cout << "This marker cannot be refilled." << endl;
        } else if (inkStatus) {
          cout << "Refill is not necessary right now." << endl;
        } else {
            inkStatus = true; 
            cout << "The marker has been refilled." <<endl;
        }
    }
};
int main() {
    BoardMarker myMarker("Dollar", "Black", true);
    myMarker.write(); 
    myMarker.setInkStatus(false);
    myMarker.write(); 
    myMarker.refill();
    myMarker.write(); 
    return 0;
}
