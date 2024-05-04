#include "iostream"
using namespace std;
template <class T1, class T2>
 class Pet{
    T1 name;
    T2 age;
    public:
    Pet(T1 n, T2 a):name(n), age(a){}
    virtual void makeSound() = 0;
    void display() { cout << "Name: " << name << "\nAge: " << age << endl; }
};
class Cat: public Pet<string, int>
{
    public:
    Cat(string n, int a):Pet<string, int>(n, a){}
    void makeSound(){
        cout << "Meow" << endl;
    }
};
class Dog: public Pet<string, int>
{
    public:
    Dog(string n, int a):Pet<string, int>(n, a){}
    void makeSound(){
        cout << "Woof" << endl;
    }
};
class Bird: public Pet<string, int>
{
    public:
    Bird(string n, int a):Pet<string, int>(n, a){}
    void makeSound(){
        cout << "Chirp" << endl;
    }
};
int main()
{
    Pet<string, int>* ptr;
    Bird bird ("Rio", 3);
    Cat cat ("Tom", 5);
    Dog dog ("Courage", 8);
    ptr = &bird;
    ptr->makeSound();
    ptr->display();
    ptr = &cat;
    ptr->makeSound();
    ptr->display();
    ptr = &dog;
    ptr->makeSound();
    ptr->display();


}