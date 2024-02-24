#include <iostream>
#include <vector>
#include <cctype>
#define SKILLS 2
using namespace std;
bool isAllDigits(const std::string& str) {
    for (char const &c : str) {
        if (!std::isdigit(c)) {
            return false; // Found a non-digit character
        }
    }
    return true; // Every character was a digit
}
void menu(string name) {
	cout << "Welcome " << name << "!" << endl
		 << "Virtual Pet Adoption System" << endl
		 << "\t1. Add pet" << endl
		 << "\t2. Show all pets" << endl
		 << "\t3. Adopt pet" << endl
		 << "\t4. Show adopted pets" << endl
		 << "\t5. Interact with pet" << endl
		 << "\t6. Return pet" << endl
		 << "\t7. Exit" << endl
		 << ">> ";
}
class Pet{
    private:
    string healthStatus;
    unsigned int hungerLevel, happinessLevel;
    string specialSkills[SKILLS];
    void updateHealth(string health){
        healthStatus = health;
    }
    public:

    Pet(int hunger, int happiness, string skill1, string skill2): hungerLevel(hunger), happinessLevel(happiness), specialSkills({skill1, skill2}){}
    void updateHunger(unsigned int hunger){
        if(hunger<=10){
        hungerLevel = hunger;
        }
        if(hungerLevel<6){
            updateHappiness(getHappinessLevel()-1);
            updateHealth("Hungry");
        }
        else{
            updateHappiness(getHappinessLevel()+1);
            updateHealth("Well fed");
        }
    }
    void updateHappiness(unsigned int happiness){
        if(happinessLevel<=10){
        happinessLevel = happiness;
        if(happinessLevel>6){
            updateHealth("Happy");
        }
        if(happinessLevel<6){
            updateHealth("Sad");
        }
        }
    }
    unsigned int getHungerLevel()const{
        return hungerLevel;
    } 
    string getHealthStatus()const{
        return healthStatus;
    }
    unsigned int getHappinessLevel() const{
        return happinessLevel;
    }
    void displayPetDetails(){
        cout<<"Health Status: "<<getHealthStatus()<<endl;
        cout<<"Hunger Level: "<<getHungerLevel()<<endl;
        cout<<"Happiness Level: "<<getHappinessLevel()<<endl;
        cout<<"Special Skills"<<endl;
        for(string s: specialSkills)cout<<s<<endl;
        cout<<endl;
    }
};
class Adopter{
    private:
    string adopterName, adopterMobileNum;
    vector<Pet>adoptedPetRecords;
    public:
    void adoptPet(Pet p){
        adoptedPetRecords.push_back(p);
    }
    void returnPet(Pet p){
        for(int i=0; i<adoptedPetRecords.size();i++){
            if(&adoptedPetRecords[i] == &p){
                adoptedPetRecords.erase(adoptedPetRecords.begin()+i);
            }
        }    
    }
    void displayAdoptedPets(){
        for(Pet p: adoptedPetRecords){p.displayPetDetails();}
    }
    void setMobileNum(string num){
        if(num.size()==10 && isAllDigits(num)==true){
            adopterMobileNum = num;
        }
        else{
            cout<<"Invalid Input"<<endl;
        }

    }
    Adopter(string name, string num):adopterName(name){
        setMobileNum(num);
    }
};
int main(){


}