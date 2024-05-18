#include "iostream"
#define SIZE 3
using namespace std;
class Appliance{
    bool isOn;
    string name;
    public:
    Appliance(string name, bool isOn = false): name(name){}
    bool turnOn(){
        if(isOn)return false;
        isOn = true;
        return true;
    }
    bool getState(){return isOn;}
};
class WirelessConnection{
    string networks[SIZE] = {"n1", "n2", "n3"};
    string pwds[SIZE] = {"p1", "p2", "p3"};
    bool connected;
    public:
    void connect(string network, string pwd){
        bool flag = false;
        for (int i=0; i<SIZE; i++)
        {
            if(network == networks[i] && pwd == pwds[i])
            {
                flag=true;
                break;
            }
        }
        if(flag) connected = true;
        else {
            connected = false;
            cout<<"failed to connect"<<endl;
        }
    }
    void disconnect(){
        connected = false;
    }
    bool isConnected() const{
        return connected;
    }
};
class Light :  public Appliance, public WirelessConnection{
    double brightness;
    public:
    Light(string name, bool isOn = false, double b = 0): Appliance(name, isOn), brightness(b){}
    bool changeBrigtness(double bright){ //the user will enter negative value to decrease brighntess
        if(brightness + bright < 0 || brightness + bright > 20) return false; 
        brightness += bright;
        return true;
    }
};
class Televison : public Appliance, public WirelessConnection{
    int channelList[SIZE] = {1,2,3};
    int currentChannel;
    public:
    Televison(string name,int c,bool isOn = false): Appliance(name, isOn), currentChannel(c){}
    bool changeChannel(int channel){
        bool flag = false;
        if(getState() && isConnected()){
            for(int c: channelList){
              if(c == channel){
                currentChannel = channel;
                flag = true;
                break;
              } 
            }
        }
        if(!flag)cout<<"channel doesn't exist"<<endl;
    return flag;
    }
};
int main()
{
    Light light("Samsung");
    light.turnOn();
    light.changeBrigtness(-30);
    light.changeBrigtness(11);
    light.changeBrigtness(-5);
    Televison tv("LED", 0);
    tv.turnOn();
    tv.connect("l", "2");
    tv.connect("n1", "p1");
    tv.changeChannel(4);
    tv.changeChannel(2);
    return 0;
}
