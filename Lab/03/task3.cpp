#include <iostream>
using namespace std;
class Task{
    private:
    string details, date;
    int month;
    public:
    void setDetails(string Details){
        details = Details;
    }
    void setDate(string Date){
        date = Date;
    }
    void setMonth(int Month){
        if(Month>0 && Month<=12){
            month = Month;
        }
        else{
            cout<<"Invalid input";
        }
    }
    string getDetails(){
        return details;
    }
    string getDate(){
        return date;
    }
    int getMonth(){
        return month;
    }
};
class Calendar
{
private:
    
public:
    Calendar(/* args */);
    ~Calendar();
};

Calendar::task3(/* args */)
{
}

Calendar::~task3()
{
}

int main(){

}