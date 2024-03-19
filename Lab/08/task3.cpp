#include <iostream>
using namespace std;
class Position{
    int x,y,z;
    public:
    Position(int a, int b, int c):x(a), y(b), z(c){}
    void display_coord(){
        cout<<"Coordinates\nx: "<<x<<"\ny: "<<y<<"\nz: "<<z<<endl;
    }
};
class Health{
    int health;
    public:
    Health(int h):health(h){}
    void display_health(){
        cout<<"Health: "<<health<<endl;
    }
};
class Character: public Position, public Health{
    string name;
    public:
    Character(int a, int b, int c, int h, string n): Position(a,b,c), Health(h), name(n){}
    void attack(){
        cout<<name<<" Attacks!"<<endl;
    }
    void heal(){
        cout<<name<<" Healed"<<endl;
    }
    
};
int main(){
    Character c(1,2,3,80,"Leo");
    c.display_coord();
    c.display_health();
    c.attack();
    c.heal();
    return 0;
}