#include<iostream>
using namespace std;
class RollerCoaster{
    private:
    string name;
    float height, length, speed;
    unsigned short capacity, current_riders;
    bool ride_inprog;
    public:
    void setName(string name){
        this->name=name;
    }
    void setHeight(float height){
        this->height = height;
    }
    void setLength(float length){
        this->length=length;
    }
    void setSpeed(float speed){
        this->speed=speed;
    }
    void setCapacity(unsigned short capacity){
        this->capacity=capacity;
        if(capacity%2 != 0 || capacity%3 != 0){
            capacity = (capacity + 1) / 2*2;
            if(capacity<=3){
                capacity+=3;
            }
        }
    }
    void setCurrentRiders(unsigned current_riders){
        this->current_riders = current_riders;
    }
    void isRideInProg(bool ride_inprog){
        this->ride_inprog = ride_inprog;
    }
    string getName()const{
        return name;
    }
    float getHeight()const{
        return height;
    }
    float getLength() const{
        return length;
    }
    float getSpeed() const{
        return speed;
    }
    unsigned short getCapacity() const{
        return capacity;
    }
    unsigned short getCurrentRiders()const{
        return current_riders;
    }
    bool isRideInProg() const{
        return ride_inprog;
    }
    void stopRide(){
        if(ride_inprog)
        {
            ride_inprog = false;
            speed = 0;
            cout<<"Ride stopped"<<endl;
        }
        else{
            cout<<"Ride is already is progress"<<endl;
        }
    }
    int seatRiders(int passengers){
        if(current_riders+passengers <= capacity && ride_inprog==false){
            current_riders +=passengers;
            cout<<passengers<<" Riders seated"<<endl;
            return 0;
        }
        else{
            current_riders = capacity;
            return abs(capacity - (current_riders+passengers));
        }
    }
    int startRide(){
        if(ride_inprog)return -1;
        if(current_riders == capacity){
            ride_inprog = true;
            speed=10;
            cout<<"Ride started"<<endl;
            return 0;
        }
        else{
            return capacity - current_riders;
        }
    }
   void unseatRiders(int passengers){
    if(passengers>0 && passengers<=capacity && ride_inprog ==false){
        current_riders -= passengers;
    }
   }
   void accelerate(string roll) {
    	for (auto it = roll.end()-1; it >= roll.begin(); it--) {
    		if (*it == '0') continue;
    		this->setSpeed(speed + (*it-'0'));
    		return;
    	}
    }
   void decelerate(string roll) {
    	for (auto it = roll.begin(); it < roll.end(); it++) {
    		if (*it == '0') continue;
    		this->setSpeed(speed - (*it-'0'));
    		return;
    	}
    }
    RollerCoaster(string name, float height, float length, unsigned short capacity): name(name), height(height), length(length), capacity(capacity), ride_inprog(false), speed(0){
        if(capacity%2 != 0 || capacity%3 != 0){
            capacity = (capacity + 1) / 2*2; //rounding off to closest multiple of 2
            if(capacity<=3){
                capacity+=3;
            }
        }
    }
    RollerCoaster(){
        name = "roller coaster";
        height = 500;
        length = 2000;
        capacity = 20;
        ride_inprog = false;
    }
};
int main(){
    RollerCoaster rc1;
    RollerCoaster rc2("roller coaster 2", 550, 1800, 15);
    cout << rc2.getName() << " " << rc2.getCapacity() << endl;
    rc2.seatRiders(15);
    rc2.startRide();
	rc2.stopRide();
    rc2.unseatRiders(12);
    cout << "Riders not seated: " << rc2.seatRiders(39) << endl;
	cout << "Current riders: " << rc2.getCurrentRiders() << endl;
	cout << "Not occupied seats: " << rc2.startRide() << endl;
    rc2.accelerate("0055");
	cout << "Speed: " << rc2.getSpeed() << endl;
	rc2.decelerate("0055");
	cout << "Speed: " << rc2.getSpeed() << endl;
	rc2.stopRide();
	cout << "Ride status: ";
    if(rc2.isRideInProg()) cout<<" in progress"<<endl;
    else cout<<" not in progress"<<endl;
	rc2.unseatRiders(3);
	cout << "Current riders: " << rc2.getCurrentRiders() << endl;

}