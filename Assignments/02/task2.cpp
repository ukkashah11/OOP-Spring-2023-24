#include <iostream>
#include <vector>
using namespace std;
class Enemy;
class Player{
    static int id;
    int playerID, health;
    string playerName;
    public:
    Player(string name):playerName(name), health(100){
        id++;
        playerID = id;
    }
    string getName()const{
        return playerName;
    }
    int getHealth()const{
        return health;
    }
    void setHealth(const int h){
        health = h;
    }
};
int Player :: id;
class Weapon{
    string weaponsList[5];
    void displayWeapons(){
    for(int i=0; i<5; i++){
        cout<<i+1<<". "<<weaponsList[i]<<endl;
   }
    }
    public:
    Weapon(){
        weaponsList[0] = "Blades of Chaos";
        weaponsList[1] = "Leviathan Axe";
        weaponsList[2] = "Draupnir Spear";
        weaponsList[3] = "Mjolnir Hammer";
        weaponsList[4] = "Ingrid Sword";
    }
    string use(){
    int choice;
    displayWeapons();
    cout<<"Enter choice of Weapon: ";
    cin>>choice;
    return weaponsList[choice-1];
   }
};
class Character : public Player{
    Weapon w;
    int level, points;
    string experience, weapon;
    public:
    Character(string name):level(0), points(0), experience("Beginner"), Player(name){}
    void levelUp(){
        points+=10;
        level+=1;
        if(experience=="Beginner")experience="Intermediate";
        if(experience=="Intermediate")experience="Advanced";
        if(experience=="Advanced")experience="Expert";
        cout<<getName()<<" levelled up!\nExperience upgraded to "<<experience<<endl;
    }
    string getExperience() const{
        return experience;
    }
    void playGame(Enemy* e);
};
class Enemy: public Player{
   Weapon w;
   string weapon;
   int damage;
   public:
   Enemy(string name, int d): damage(d), Player(name){}
   void attack(Character* c);
};
void Character::playGame(Enemy* e){
        weapon=w.use();
        cout<<getName()<<" used "<<weapon<<" to attack!"<<endl;
        e->setHealth(e->getHealth()-5);
        levelUp();
    }
void Enemy::attack(Character* c){
    weapon = w.use();
    cout<<getName()<<" attacked with "<<weapon<<endl;
    c->setHealth(c->getHealth()-damage);
   }
int main()
{
    cout<<"SYED UKKASHAH\n23K-0055\n\n";
    Character c("Kratos");
    Enemy e("Zeus", 10);
    for (int i = 0; i < 3; i++) {
    cout << "Character experience: " << c.getExperience() << "\n";
    cout << "Character health: " << c.getHealth() << "\n";
    c.playGame(&e);
    cout << "Enemy health: " << e.getHealth() << "\n";
    e.attack(&c);
    }
}
