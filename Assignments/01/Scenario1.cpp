#include <iostream>
#include <vector>
#include <cctype>
#include<cstdlib>
#define SKILLS 2
using namespace std;
const string health[4] = { "Very Healthy", "Healthy", "Sick", "Very Sick" };
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
    string healthStatus = health[1], Species, specialSkills[SKILLS], petName; 
    unsigned int hungerLevel = 7, happinessLevel = 6;
    public:
    Pet(string name, string species, string skill1, string skill2): petName(name), Species(species), specialSkills({skill1, skill2}){}
    void setName(string name){
        petName = name;
    }
    string getPetName() const{
        return petName;
    }
    void setSpecies(string species){
        Species = species;
    }
    string getSpecies()const{
        return Species;
    }
    void updateHealth(string health){
        healthStatus = health;
    }
    void updateHunger(unsigned int hunger){
        if(hunger<=10){
        hungerLevel = hunger;
        }
    }
    void updateHappiness(unsigned int happiness){
        if(happinessLevel<=10){
        happinessLevel = happiness;
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
        cout<<"Pet Name: "<<getPetName()<<endl;
        cout<<"Species: "<<getSpecies()<<endl;
        cout<<"Health Status: "<<getHealthStatus()<<endl;
        cout<<"Hunger Level: "<<getHungerLevel()<<endl;
        cout<<"Happiness Level: "<<getHappinessLevel()<<endl;
        cout<<"Special Skills"<<endl;
        for(string s: specialSkills)cout<<s<<endl;
        cout<<endl;
    }
};
Pet getPetDetails(){
    string name, skill1, skill2, species;
    cout<<"Enter pet name: ";
    getline(cin, name);
    cout<<"Enter Species: ";
    getline(cin, species);
    cout<<"Enter skills: ";
    getline(cin, skill1);
    getline(cin, skill2);
    return Pet(name, species, skill1, skill2);
}
class Adopter{
    public:
    vector<Pet>adoptedPetRecords;
    string adopterName, adopterMobileNum;
    void adoptPet(vector<Pet>& pets, string name){
        for(int i=0; i<pets.size(); i++){
            if(pets[i].getPetName()==name){
                pets.erase(pets.begin()+i);
                adoptedPetRecords.push_back(pets[i]);
                cout<<"Pet adopted"<<endl;
            }
            else{
                cout<<"Pet not found"<<endl;
            }
        }
    }
    void returnPet(string name, vector<Pet>& pets){
        for(int i=0; i<adoptedPetRecords.size(); i++){
            if(adoptedPetRecords[i].getPetName()==name){
                pets.push_back(adoptedPetRecords[i]);
                adoptedPetRecords.erase(adoptedPetRecords.begin()+i);
                cout<<"Pet returned"<<endl;
            }
        }    
    }
    void displayAdoptedPets(){
        for(Pet p: adoptedPetRecords){p.displayPetDetails();}
    }
    void setMobileNum(string num){
        if(num.size()==11 && isAllDigits(num)==true){
            adopterMobileNum = num;
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
    }
    void interactWithPet(string name, vector<Pet>& pets){
         for(int i=0; i<pets.size(); i++){
            if(pets[i].getPetName()==name){
                int choice, mood, hunger;
                string name;
                cout<<"\tEnter 1 to change Pet's happiness levels"<<endl;
                cout<<"\tEnter 2 to change Pet's hunger levels"<<endl;
                cout<<"\tEnter 3 to change Pet's name"<<endl;
                cin>>choice;
                switch (choice){
                    case 1:
                    cout<<"Enter Pet happiness level from 1-10: ";
                    cin>>mood;
                    if(mood<0 || mood>10){
                        cout<<"Invalid input"<<endl;
                    }
                    else{
                    pets[i].updateHappiness(mood);
                    }
                    break;
                    case 2:
                    cout<<"Enter Hunger Levels (1-10): ";
                    cin>>hunger;
                    pets[i].updateHunger(hunger);
                    break;
                    case 3:
                    cout<<"Enter Pet's name: ";
                    getline(cin, name);
                    pets[i].setName(name);
                    break;
                    default:
                    cout<<"Invalid input"<<endl;
                }
                if (pets[i].getHungerLevel() >= 8 && pets[i].getHappinessLevel()>= 8) pets[i].updateHealth(health[0]);
	           else if (pets[i].getHungerLevel() >= 60 && pets[i].getHappinessLevel() >= 60) pets[i].updateHealth(health[1]);
	           else if (pets[i].getHungerLevel() >= 40 && pets[i].getHappinessLevel() >= 40) pets[i].updateHealth(health[2]);
	           else pets[i].updateHealth(health[3]);
            }
            else{
                cout<<"Pet not found"<<endl;
            }
            
        }
    }
    Adopter(string name, string num):adopterName(name){
        setMobileNum(num);
    }
};
int main(){
cout<<"SYED UKKASHAH\n23K-0055\n"<<endl;
vector<Pet> Pets;
string adopter_name, contact, pet_name;
int choice=0;
cout<<"Enter your name: ";
getline(cin, adopter_name);
cout<<"Enter your Phone Number: ";
getline(cin,contact);
Adopter adopter(adopter_name,contact);
do{
menu(adopter.adopterName);
cin>>choice;
cin.ignore();
switch(choice){
    case 1:
    Pets.push_back(getPetDetails());
    break;
    case 2:
    for(Pet p: Pets)p.displayPetDetails();
    break;
    case 3:
    cout<<"Enter Pet Name: ";
    getline(cin, pet_name);
    adopter.adoptPet(Pets,pet_name);
    break;
    case 4:
    adopter.displayAdoptedPets();
    break;
    case 5:
    cout<<"Enter name of Pet to interact with: ";
    getline(cin, pet_name);
    adopter.interactWithPet(pet_name, adopter.adoptedPetRecords); //assumed we can only interact with pets we adopted
    break;
    case 6:
    cout<<"Enter name of pet to be returned: ";
    getline(cin, pet_name);
    adopter.returnPet(pet_name, Pets);
    break;
    case 7:
    exit(0);
}
}while(choice>0 && choice<=7);
}