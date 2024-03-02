/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
/*
the question asked to initialize the days array in the default constructor and not in the parameterized one
however, when instantiating a class using a param. cons., the days array will have null strings stored.
therefore, i've moved the initialization of the days array to the top
*/
#include <iostream>
using namespace std;
class WeekDays{
    private:
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int CurrentDay;
    public:
    WeekDays(int day){
        setCurrentDay(day);
    }
    void setCurrentDay(int d){
        if(d>6){
            CurrentDay = d%6;
        }
        else{
            CurrentDay = d;
        }
    }
    string getCurrentDay(){
        return Days[CurrentDay];
    }
    string getNextDay(){
        if(CurrentDay+1 > 6){
            return Days[(CurrentDay + 1) % 7];
        }
        else{
            return Days[CurrentDay+1];
        }
    }
    string getPreviousDay(){
        if(CurrentDay-1 < 0){
            return Days[(CurrentDay - 1) % 7];
        }
        else{
            return Days[CurrentDay-1];
        }
    }
    string getNthDay(int n){
        if(CurrentDay+n > 6){
            return Days[(CurrentDay +n) % 7];
        }
        else{
            return Days[CurrentDay+n];
        }
    }
};
int main(){
    int day,n;
    cout<<"Enter Current day: ";
    cin>>day;
    WeekDays d(day);
    cout<<"Current Day: "<<d.getCurrentDay()<<endl;
    cout<<"Next Day: "<<d.getNextDay()<<endl;
    cout<<"Previous Day: "<<d.getPreviousDay()<<endl;
    cout<<"Enter Nth Day: ";
    cin>>n;
    cout<<"Nth Day: "<<d.getNthDay(n)<<endl;


    
    
}