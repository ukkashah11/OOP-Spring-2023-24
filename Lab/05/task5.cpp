/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include<iostream>
using namespace std;
class Engine{
    string name, fuel;
    float HP;
    public:
    Engine(string n, string f, float hp):name(n), fuel(f), HP(hp){}
    void display() const {
        cout << "Engine Name: " << name << ", Fuel: " << fuel << ", Horsepower: " << HP << " Watts" << endl;
    }
};
class Wheels{
    string type;
    float diameter;
    public:
    Wheels(string t, float d): type(t), diameter(d){}
    void display() const {
        cout << "Wheels Type: " << type << ", Diameter: " << diameter << " inches" << endl;
    }
};
class Headlights{
    const string type = "LED";
    public:
    void display() const {
        cout << "Headlights Type: " << type << endl;
    }
};
class Steering{
    float diameter;
    public:
    Steering(float d):diameter(d){}
    void display() const {
        cout << "Steering Wheel Diameter: " << diameter << " inches" << endl;
    }
};
class Car{
    Engine* e;
    Steering* steer;
    Wheels* w;
    string name;
    Headlights h;
    unsigned int seats;
    float price;
    public:
    Car(string n, unsigned int s, float p, Engine* e, Steering* steer, Wheels* w):name(n), seats(s), price(p), e(e), w(w), steer(steer){}
    void display() const {
        cout << "Car Name: " << name << endl;
        cout << "Seats: " << seats << endl;
        cout << "Price: $" << price << endl;
        e->display();
        steer->display();
        w->display();
        h.display();
    }
};
int main(){
    Engine e1("Toyota Engine", "Gasoline", 12000);
    Steering steering(13);
    Wheels w("Sport", 90);
    Car c1("Toyota Corolla", 4, 8000.99, &e1, &steering, &w); /*Aggregation: Engine, Steering, Wheels classes
                                                                Association: Headlights class*/
    c1.display();
}

