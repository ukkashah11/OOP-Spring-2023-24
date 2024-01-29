#include <iostream>
#include <string>
#include <limits> 
using namespace std;
class Event{
    private:
    string date, name, venue, organizer; 
    public:
    void setDate(string Date){
         date=Date;
    }
    void setName(string Name){
        name = Name;
    }
    void setVenue(string Venue){
        venue = Venue;
    }
    void setOrganizer(string Organizer){
        organizer = Organizer;
    }
    string getName(){
        return name;
    }
    string getDate(){
        return date;
    }
    string getVenue(){
        return venue;
    }
    string getOrganizer(){
        return organizer;
    }
};
Event* findEvent(Event events[],string date, int size){ //returns null pointer if event not found
        for(int i=0; i<size; i++){
            if(events[i].getDate()==date){
                return &events[i];
            }
        }
        return nullptr;
    }
void displayDetails(Event* e){ //function displays details of event
    cout<<"Event Name: "<<e->getName()<<endl;
    cout<<"Event Date: "<<e->getDate()<<endl;
    cout<<"Event Organizer: "<<e->getOrganizer()<<endl;
    cout<<"Event Venue: "<<e->getVenue()<<endl;
}
int main(){
    string name, venue, org, date;
    cout<<"Enter number of events you wish to manage: ";
    int size;
    cin>>size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes newline in buffer  
    Event* events = new Event[size];
    for(int i=0; i<size; i++){
        cout<<"Enter name for Event "<<i+1<<": ";
        getline(cin, name);
        events[i].setName(name);
        cout<<"Enter name of Event Organizer: ";
        getline(cin, org);
        events[i].setOrganizer(org);
        cout<<"Enter name of Event Venue: ";
        getline(cin,venue);
        events[i].setVenue(venue);
        cout << "Enter event date (DD/MM/YYYY): ";
        getline(cin, date);
        events[i].setDate(date);
    }
    cout<<"Enter Event Date to search (DD/MM/YYYY): ";
    string find;
    getline(cin,find);
    Event *e = findEvent(events, find, size);
    if(e == nullptr){
        cout<<"No events found on this date"<<endl;
    }
    else{
        displayDetails(e);
    }
    delete[] events;
    return 0;
}