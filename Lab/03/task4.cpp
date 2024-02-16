#include <iostream>
using namespace std;
class Smartphone{
    private:
    string brand, model, display;
    int ram, rom, storage;
    public:
    void setBrand(string Brand){
        brand = Brand;
    }
    void setModel(string Model){
        model = Model;
    }
    void setDisplay(string Display){
        display = Display;
    }
    void setRAM(int RAM){
        ram = RAM;
    }
    void setROM(int ROM){
        rom = ROM;
    }
    void setStorage(int Storage){
        storage = Storage;
    }
    string getBrand(){
        return brand;
    }
    string getModel(){
        return model;
    }
    string getDisplay(){
        return display;
    }
    int getRAM(){
        return ram;
    }
    int getROM(){
        return rom;
    }
    int getStorage(){
        return storage;
    }
    void PhoneCall(){
        cout<<"Making phone call..."<<endl;
    }
    void Messages(){
        cout<<"Sending messages..."<<endl;
    }
    void Connecting(){
        cout<<"Connecting to Wi-Fi..."<<endl;
    }
    void Browsing(){
        cout<<"Browsing the internet..."<<endl;
    }
};
int main(){
    Smartphone s1, s2;
    s1.setBrand("Samsung");
    s1.setDisplay("6 Inch display");
    s1.setModel("S1");
    s1.setRAM(8);
    s1.setROM(4);
    s1.setStorage(100);
    s2.setBrand("Apple");
    s2.setDisplay("7 Inch display");
    s2.setModel("X");
    s2.setRAM(16);
    s2.setROM(6);
    s2.setStorage(128);
    cout<<s1.getBrand()<<"\n"<<s1.getDisplay()<<"\nModel: "<<s1.getModel()<<"\n"<<s1.getRAM()<<" GB RAM\n"<<s1.getROM()<<" GB ROM\n"<<s1.getStorage()<<" GB Storage\n";
    s1.Connecting();
    cout<<"\n\n";
    s1.Browsing();
    cout<<"\n";
    cout<<"\n"<<s2.getBrand()<<"\n"<<s2.getDisplay()<<"\nModel: "<<s2.getModel()<<"\n"<<s2.getRAM()<<" GB RAM\n"<<s2.getROM()<<" GB ROM\n"<<s2.getStorage()<<" GB Storage\n";
    s2.Messages();
    cout<<"\n\n";
    s2.PhoneCall();
    cout<<"\n";
    return 0;
}