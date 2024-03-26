#include <iostream>
using namespace std;
class SecurityTool{
    float cost;
    int devices;
    string securityLevel;
    public:
    SecurityTool(float c, int d, string sl):cost(c), devices(d), securityLevel(sl){}
    void performScan(){
        cout<<"Scanning for threats..."<<endl;
    }
};
