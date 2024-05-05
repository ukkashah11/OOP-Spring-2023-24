#include "iostream"
#include "cmath"
using namespace std;
class Drone{
    protected:
    float latitude, longtitude, altitude, speed;
    public:
    Drone(float lat, float lon, float alt, float s):latitude(lat), longtitude(lon), altitude(alt), speed(s){}
    void adjustAltitude(const float meters){altitude = meters;}
    void setSpeed(const float speed){
        try
        {
            if(speed<0)throw "Invalid speed"; //exception handling if speed is invalid
            else this->speed = speed;
        
        }
        catch(char* ex)
        {
            cout<<ex;
        }
    }
};
class Flyable{
    public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};
class Scannable{
    public:
    virtual void scanArea(float radius) = 0;
};
class ReconDrone : public Drone, public Flyable, public Scannable{
    float cameraResolution, maxFlightTime;
    public:
    ReconDrone(float lat, float lon, float alt, float s, float cam_res, float max_time):Drone(lat, lon, alt, s), cameraResolution(cam_res), maxFlightTime(max_time){}
    void takeoff(){cout << "ReconDrone takeoff" << endl;}
    void land(){cout << "ReconDrone land" << endl;}
    void navigateTo (float latitude, float longitude, float altitude) override{
        float dx = latitude - this->latitude;
        float dy = longitude - this->longtitude;
        float dz = altitude - this->altitude;
        float distance = sqrt(pow(dx,2) + pow(dy, 2) + pow(dz,2));
        cout<<"Time required to reach coordinates: "<<distance/speed<<" seconds"<<endl;
    }
    void scanArea(float radius){
        cout << "Scanning area within radius: " << radius << " meters." << endl;
        // For simulation purposes, let's assume we detect a random number of objects.
        int detectedObjects = rand() % 10; // Random number of objects from 0 to 9
        cout << "Detected " << detectedObjects << " objects within the radius." << endl;
    }
};
int main()
{
    cout<<"Syed Ukkashah Ahmed Shah\n23K-0055\n"<<endl;
    ReconDrone myDrone(34.05, -118.2437, 500, 12, 2.5, 10);
    myDrone.takeoff();
    myDrone.setSpeed(100); // Setting speed to 100 km/h
    myDrone.navigateTo(34.0522, -118.3437, 700);
    myDrone.scanArea(500);
    myDrone.land();
    return 0;

}