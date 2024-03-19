#include <iostream>
using namespace std;
class Character{
    int health, damage;
    public:
    Character(int h, int d):health(h), damage(d){}
    void character_display(){
        cout<<"Health: "<<health<<endl;
        cout<<"Damage: "<<damage<<endl;
    }
};
class Enemy:public Character{
    public:
    Enemy(int h, int d):Character(h,d){}
    void enemy_display(){
        cout<<"Enemy stats\n";
        character_display();
    }
};
class Player: public Character{
    public:
    Player(int h, int d):Character(h,d){}
    void player_display(){
       cout<<"Player stats\n";
       character_display();
    }
};
class Wizard: public Player{
    int magic_pwr;
    string spells;
    public:
    Wizard(int pwr, string s,int h, int d):magic_pwr(pwr), spells(s),Player(h,d){}
    void wizard_display(){
        cout<<"Wizard stats\n";
        character_display();
        cout<<"Magic Power: "<<magic_pwr<<endl;
        cout<<"Spells: "<<spells<<endl;
    }
};
int main()
{
    Wizard w(80, "Fireball", 75, 88);
    w.wizard_display();
    return 0;
}