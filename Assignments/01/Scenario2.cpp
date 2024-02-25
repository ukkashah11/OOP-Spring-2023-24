/*Syed Ukkashah Ahmed Shah
  23K-0055
  Added comments where necessary
*/
#include<iostream>
using namespace std;
class Table{
    private:
    int total_seats,occupied_seats = 0,free_seats = total_seats;
    bool clean = true;
    void setTotalSeats(int total){
        if(total == 4 || total == 8){
            total_seats = total;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
    }
    public:
    void occupySeats(int occupy){
        if(occupy<=total_seats){
            occupied_seats = occupy;
            free_seats = total_seats - occupy;
            if(occupy!=0) cout<<"Table Occupied"<<endl;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
    }
    void haveLunch(){
        setCleanliness(false);
        cout<<"Having lunch..."<<endl;
    }
    void leaveTable(){
        occupySeats(0);
        cout<<"Leaving the table..."<<endl;
    }
    void useTable(){
        if(getCleanliness())cout<<"Using the table..."<<endl;
        else cout<<"Table can't be used..."<<endl;
    }
    void setCleanliness(bool state){
        clean = state;
        if(state)cout<<"Cleaning the table..."<<endl;
    }
    int getOccupiedSeats() const{
        return occupied_seats;
    }
    bool getCleanliness() const{
        return clean;
    }
    int getTotalSeats()const{
        return total_seats;
    }
    Table(int total){
        setTotalSeats(total);
    }
};
void OccupyTable(Table tables[], int size, int totalTables){
    bool flag=true;
    for(int i=0; flag == true; i++){
        if(tables[i].getOccupiedSeats() == 0 && tables[i].getCleanliness()==true && tables[i].getTotalSeats()>=size){
        tables[i].occupySeats(size);
        flag = false;
        }
    }
    if(flag)cout<<"No tables available"<<endl;
}
void EmptyTable(int number, Table tables[], int total_tables){
    if(number>0 && number<=total_tables){
        tables[number].occupySeats(0);
        tables[number].setCleanliness(true);
        cout<<"Emptying the Table..."<<endl;
    }
}
int main(){
    cout<<"SYED UKKASHAH\n23K-0055\n\n"<<endl;
    Table tables[5] = {8,8,4,4,4};
    OccupyTable(tables,4,5);
    OccupyTable(tables,6,5);
    tables[0].useTable();
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].setCleanliness(true);
    EmptyTable(1,tables,5);

}