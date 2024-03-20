#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string make, model;
    int year;
    public:
    Vehicle(string make, string model, int year): make(make), model(model), year(year){}
    virtual void display() const {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year;
    }
};
class Car: public Vehicle{
    protected:
    int doors, fuel_efficiency;
    public:
    Car(int d, int f, string make, string model, int year):Vehicle(make, model, year), doors(d), fuel_efficiency(f){}
     void display() const override {
        Vehicle::display(); // Call base class display
        cout << ", Doors: " << doors << ", Fuel Efficiency: " << fuel_efficiency << " MPG";
    }
};
class ElectricCar: public Car{
    int battery_life;
    public:
    ElectricCar(string make, string model, int year, int d, int f, int b): Car(d, f, make, model, year), battery_life(b){}
    void display() const override {
        Car::display(); // Call base class display
        cout << ", Battery Life: " << battery_life << " hours" << endl;
    }
};
int main(){
    ElectricCar ec ("Tesla", "Model S", 2022, 4, 120, 24);
    ec.display(); // Display all details of the ElectricCar
    return 0;
}