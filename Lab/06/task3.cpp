#include <iostream>
using namespace std;
class Appointment{
    static int total, earnings;
    string details;
    int cost;
    public:
    Appointment(string details, float earns):details(details), cost(earns){
        total++;
        earnings+=cost;
    }
    void setDetails(const string det){
        details = det;
    }
    float static getAvgCost(){
        return (float)earnings/total;
    }
    void printAppointmentDetails(){
        cout<<details<<endl;
        cout<<"Cost: $"<<cost<<endl;
    }
};
int Appointment::total;
int Appointment::earnings;
int main(){
    Appointment a1("Facial, 1:30PM", 10);
    a1.printAppointmentDetails();
    cout<<"\nAverage Appointment Cost: "<<Appointment::getAvgCost()<<endl;
    Appointment a2("Haircut, 2:00PM", 15);
    a2.printAppointmentDetails();
    cout<<"\nAverage Appointment Cost: "<<Appointment::getAvgCost()<<endl;
    Appointment a3("Neck Massage, 2:30PM", 20);
    a3.printAppointmentDetails();
    cout<<"\nAverage Appointment Cost: "<<Appointment::getAvgCost()<<endl;
}