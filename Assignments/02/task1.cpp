#include <iostream>
#include <vector>
using namespace std;
class SecurityTool{
    float cost;
    int devices;
    string securityLevel;
    public:
    SecurityTool(float c, int d, string sl):cost(c), devices(d), securityLevel(sl){}
    virtual void performScan(){
        cout<<"Scanning for threats..."<<endl;
    }
    string getSecurityLevel()const{
        return securityLevel;
    }
};
class FirewallTool : public SecurityTool{
  int ports [23];
  string protocols[6] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
   void generatelist(){
    for(int i=0; i<23; i++)ports[i] = i+3; //Student ID: 23K-0055 (using 2)
  }
  public:
  FirewallTool(float c, int d, string sl):SecurityTool(c,d,sl){
  }
 
  void performScan(){
    generatelist();
    int i;
    if(getSecurityLevel() == "HIGH"){
        cout<<"Allowed Protocols: \n";
        for(string p: protocols)cout<<p<<endl;
        cout<<"Allowed Ports: \n";
        for(int ps: ports)cout<<ps<<endl;
    }
    if(getSecurityLevel() == "MEDIUM"){
        cout<<"Allowed Protocols: \n";
        for(string p: protocols)cout<<p<<endl;
        cout<<"Allowed Ports: \n";
        for(int ps: ports){
            cout<<ps<<endl;
            i=ps;
        }
        cout<<i+1<<endl;
        cout<<i+2<<endl;
    }
    if(getSecurityLevel() == "LOW"){
        cout<<"Allowed Protocols: \n";
        for(string p: protocols)cout<<p<<endl;
        cout<<"TCP"<<endl;
        cout<<"DNS"<<endl;
        cout<<"\nAllowed Ports: \n";
        for(int ps: ports){
            cout<<ps<<endl;
            i=ps;
        }
        cout<<i+1<<endl;
        cout<<i+2<<endl;
        cout<<i+3<<endl;
        cout<<i+4<<endl;
        cout<<i+5<<endl;
    }
  }
};
 int main(){
    float cost;
    int devices, choice;
    string security;
    cout<<"Enter cost of security tool: ";
    cin>>cost;
    cout<<"Enter the number of devices the tool can simultaneously run on: ";
    cin>>devices;
    cout<<"Choose Security level: \n";
    cout<<"1.HIGH\n2.MEDIUM\n3.LOW\n";
    cin>>choice;
    switch(choice){
        case 1:
        security = "HIGH";
        break;
        case 2:
        security = "MEDIUM";
        break;
        case 3:
        security = "LOW";
        break;
        defualt:cout<<"Invalid input"<<endl;
    }
    if(cost>0 && devices >0 && devices <=10 ){
        FirewallTool myFireWall (cost, devices, security);  
        myFireWall.performScan(); //the scan will be performed based on user choices
    }
    else{
        cout<<"Invalid input"<<endl;
    }
 }