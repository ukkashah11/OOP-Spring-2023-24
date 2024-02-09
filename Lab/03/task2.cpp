#include <iostream>
#include <string>
using namespace std;
class WaterBottle {
private:
    string company;
    string color;
    double capacityL; 
    int capacityML; 

public:
    WaterBottle(string c, string col, double cap) : company(c), color(col), capacityL(cap), capacityML(cap * 1000) {}
    string getCompany() const { return company; }
    string getColor() const { return color; }
    double getCapacityL() const { return capacityL; }
    int getCapacityML() const { return capacityML; }
    void setCompany(const string &c) { company = c; }
    void setColor(const string &col) { color = col; }
    void setCapacity(double capL) {
        capacityL = capL;
        capacityML = static_cast<int>(capL * 1000);
    }
    void updateCapacity(int consumedML) {
        int newCapacityML = capacityML - consumedML;
        if(newCapacityML < 0) {
            cout << "Error: Consumed more than the current capacity." <<endl;
            return;
        }
        capacityML = newCapacityML;
        capacityL = capacityML / 1000.0;
    }
    void display() {
        cout << "Water Bottle by " << company << " in " << color << " color." << endl;
        cout << "Current Capacity: " << capacityL << "L (" << capacityML << "ml)" << endl;
    }
};

int main() {
    WaterBottle myBottle("HydroFlask", "Blue", 2.5);
    myBottle.display(); 
    cout << "\nAfter drinking 250ml of water:" << std::endl;
    myBottle.updateCapacity(250); 
    myBottle.display(); 

    return 0;
}
