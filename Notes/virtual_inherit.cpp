#include "iostream"
using namespace std;
class LivingThing{
    public:
    void breathe(){
        cout<<"Breathing as a living thing"<<endl;
    }
};
class Animal:virtual public LivingThing{
    public:
    void breathe(){
        cout<<"Breathing as an animal"<<endl;
    }
};
class Reptile: virtual public LivingThing{
    public:
    void crawl(){
        cout<<"crawling with the reptile"<<endl;
    }
};
class Snake: public Animal, public Reptile{};
int main(){
    Snake s;
    s.breathe();
    s.crawl();
    return 0;
}
