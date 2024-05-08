#include "iostream"
using namespace std;
class Vehicle{
    protected:
    string make, model;
    float speed;
    public:
    Vehicle(string make, string model):make(make), model(model), speed(0){}
    void virtual accelerate() = 0;
    void virtual brake() = 0;
    float virtual calculateFuelEfficiency() = 0;
    string getMake() const{return make;}
    string getModel()const{return model;}
    float getSpeed()const{return speed;}
};
class Car: public Vehicle{
    double fuelCapacity;
    public:
    Car(string make, string model, double capacity): Vehicle(make, model), fuelCapacity(capacity){}
    void accelerate(){speed+=10;}
    void brake(){
        if(speed - 5 < 0 ) speed=0;
        else speed-=5;
    }
    float calculateFuelEfficiency(){return speed*0.5;}
};
class Truck: public Vehicle{
    int cargoCapacity;
    public:
    Truck(string make, string model, int cargo): Vehicle(make, model), cargoCapacity(cargo){}
    void accelerate(){speed+=5;}
    void brake(){
        if(speed - 2 < 0 ) speed=0;
        else speed-=2;
    }
    float calculateFuelEfficiency(){return speed*0.5;}
};