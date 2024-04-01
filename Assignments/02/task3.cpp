#include <iostream>
#include <vector>
using namespace std;
class DarazPersonData{
    string lastName, firstName, address, city, state, zip, phone;
    public:
    DarazPersonData(string ln, string fn, string a, string c, string s, string z, string p): 
    lastName(ln), firstName(fn), address(a), city(c), zip(z), state(s), phone(p){}
     void setLastName(const string& lastName) {
        this->lastName = lastName;
    }
    void setFirstName(const string& firstName) {this->firstName = firstName;}
    void setAddress(const string& address) {this->address = address;}
    void setCity(const string& city) {this->city = city;}
    void setState(const string& state) {this->state = state;}
    void setZip(const string& zip) {this->zip = zip;}
    void setPhone(const string& phone) {this->phone = phone;}
    string getLastName() const {return lastName;}
    string getFirstName() const {return firstName;}
    string getAddress() const {return address;}
    string getCity() const {return city;}
    string getState() const {return state;}
    string getZip() const {return zip;}
    string getPhone() const {return phone;}
};
class DarazCustomerData:public DarazPersonData{
    int customerNumber, loyaltyPoints;
    static int id;
    public:
    DarazCustomerData(string ln, string fn, string a, string c, string s, string z, string p):
    DarazPersonData(ln,fn,a,c,s,z,p), customerNumber(id++), loyaltyPoints(0){}
    int getCustomerNumber() const {return customerNumber;}
    int getLoyaltyPoints() const {return loyaltyPoints;}
    void setCustomerNumber(int customerNumber) {this->customerNumber = customerNumber;}
    void setLoyaltyPoints(int loyaltyPoints) {this->loyaltyPoints = loyaltyPoints;}
    
};
int DarazCustomerData::id;
class DarazLoyaltyProgram{
    DarazCustomerData* customer;
    public:
    DarazLoyaltyProgram(DarazCustomerData* ptr):customer(ptr){}
    int getLoyaltyPoints() const {return customer->getLoyaltyPoints();}
    void addPoints(int points){
        customer->setLoyaltyPoints(customer->getLoyaltyPoints()+points);
    }
    float redeemPoints(int points){
        int loyaly_points = customer->getLoyaltyPoints();
        if (loyaly_points - points < 0 || points < 0) return -1.f;
        return 0.75f;
    }
     void displayLoyaltyPoints() {
        cout << "Total Loyalty Points: " << customer->getLoyaltyPoints() << endl;
    }
};
    void print(DarazCustomerData customer) {
    cout << "Customer ID: " << customer.getCustomerNumber() << "\n";
    cout << "Name: " << customer.getFirstName() + " " + customer.getLastName() << "\n";
    cout << "Address: " << customer.getAddress() << "\n";
    cout << "City: " << customer.getCity() << "\n";
    cout << "Phone: " << customer.getPhone() << "\n";
    cout << "Zip: " << customer.getZip() << "\n";
    cout << "State: " << customer.getState() << "\n";
}
int main(){
    cout<<"SYED UKKASHAH\n23K-0055\n\n";
    int loyaltyPoints;
    float item_price;
    DarazCustomerData customer("Syed","Ukkashah","Johar","Karachi","Street","11-A","03XXXXXXX79");
    print(customer);
    DarazLoyaltyProgram loyaltyProgram(&customer);
    loyaltyProgram.addPoints(100);
    loyaltyProgram.displayLoyaltyPoints();
    cout << "Enter item price: ";
    cin >> item_price;
    cout << "Enter amount of points to redeem: ";
    cin >> loyaltyPoints;
    cout << "Original Price: " << item_price << "\n";
    float discount = loyaltyProgram.redeemPoints(loyaltyPoints);
    if (discount == -1) return 1;
    cout << "Discounted Price: " << item_price * discount << "\n";

    return 0;
}
