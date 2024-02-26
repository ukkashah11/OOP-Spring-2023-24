/*Syed Ukkashah Ahmed Shah
  23K-0055
  Added comments where necessary
*/
#include <iostream>
#include <vector>
using namespace std;
class Restaurant {
public:
    string restaurant_name, location;
    vector<string> menu_list, valid_coupon_codes_list;
    vector<float> price_list;
    static int redeemed_coupons;
    string restaurant_code;
    vector<int> bill; // stores the indices of the purchased menu items
    float total;
    Restaurant(string name, string location, string code, vector<string> menu, vector<float> price) 
    : restaurant_name(name), location(location), restaurant_code(code), menu_list(menu), price_list(price), total(0)  {} //initialises total bill price "total: to 0 by default everytime constructor is called
    void display_menu() {
        for (int i = 0; i < menu_list.size(); i++)
            cout << "[" << i << "]: " <<  menu_list[i] << " -> $" << price_list[i] << endl; 
    }
    void apply_discount() { //this function iterates through the bill list twice to see if item has been ordered more than once for the "Buy 1 Get One Free discount"
        int count = 0;
        for (int i : bill) {
            for (int j : bill)
                if (i == j) count++; 
            if (count >= 2) { 
                cout << "Discounted: $" << total - price_list[i] << endl; //the price of one item is subtracted from the total price if more than two quantities of the same item are bought
                return;
            }
        }
    }
    void generate_bill() {
        for (int i : bill) {
            cout << "[" << i << "]: " <<  menu_list[i] << " -> $" << price_list[i] << endl;
            total += price_list[i];
        }
        cout << "Total: $" << total << endl;
    }
};
int Restaurant::redeemed_coupons = 0;
class BOGOCoupon {
public:
    string coupon_code, restaurant_code;
    int valid_from, valid_until;
    BOGOCoupon(string c_code, string res_code, int from, int until)
    : coupon_code(c_code), restaurant_code(res_code), valid_until(until), valid_from(from) {}
    bool is_valid(string res_code, int curr_day) {
        return (res_code != restaurant_code && curr_day >= valid_from && curr_day <= valid_until) ? false : true;
    }
};
class User {
public:
    string name, mobile_number;
    int age;
    vector<BOGOCoupon> coupons, redeemed_coupons;
    User(string name, string phone, int age) : name(name), mobile_number(phone), age(age) {}
    void accumulate_coupon(BOGOCoupon coupon) { coupons.push_back(coupon); } //coupon accumulated by inserting BOGOCoupon object in the vector
    int has_valid_coupon(string res_code) {
        for (int i = 0; i < coupons.size(); i++)
            if (!is_redeemed(coupons[i]) && coupons[i].is_valid(res_code, 8)) return i; //if a coupons is unredeemed and is valid by resteraunt code & date, index is returned
        return -1;
    }
    bool is_redeemed(BOGOCoupon coupon) {  //iterates through the redeemed coupons vector and checks whether a coupon has been redeemed or not
        for (BOGOCoupon redeemed : redeemed_coupons)
            if (coupon.coupon_code == redeemed.coupon_code) return true;
        return false;
    }
    bool redeem_coupon(int coupon, string res_code) { 
        if (!is_redeemed(coupons[coupon]) && coupons[coupon].is_valid(res_code, 8)) { //if coupon is unredeemed and valid, it is redeemed and added to the redeemed coupons vector
            redeemed_coupons.push_back(coupons[coupon]);
            return true; //return true if conditions met
        }
        return false; //returns false if coupon can't be redeemed
    }
};

void menu(User u) {
    cout << "Welcome"<<u.name<<":\n"
         << "\t1. Menus\n"
         << "\t2. Receipt\n"
         << "\t3. Add Item\n"
         << "\t4. Exit Menu\n"
         << ">> ";
}
void get_receipt(User &user, Restaurant &res){
    int index = user.has_valid_coupon(res.restaurant_code);
    cout << "Coupon available" << endl;
    cout << user.coupons[index].restaurant_code << "-BOGO-" << user.coupons[index].coupon_code << endl; //coupon details printed
    cout << "Would you like to avail the coupon? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'N' || choice == 'n') { 
        res.generate_bill();
        return;
    }

    res.generate_bill(); 
    res.apply_discount(); //possible discount applied 
    res.bill.clear(); //erasing all bill elements once receipt is generated & coupon is availed
}

User create_user() {
    string name, phone;
    int age;

    cout << "Enter user name: ";
    getline(cin, name);

    cout << "Enter user phone number: ";
    getline(cin, phone);

    cout << "Enter user age: ";
    cin >> age;

    return { name, phone, age };
}

int main()
{
    cout<<"SYED UKKASHAH\n23K-0055\n\n"<<endl;
    Restaurant r1("Food Haven", "City Center", "FH",{ "Sushi", "Pad Thai", "Mango Tango" },{ 8.99, 13.99, 9.99 });
    Restaurant r2("Pixel Bites", "Cyber Street", "PB",{ "Binary Burger", "Quantum Quinoa", "Data Donuts" },{ 12.99, 6.99, 5.99 });
    User user = create_user();
    user.accumulate_coupon(BOGOCoupon("79834", "FH", 0, 30));
    user.accumulate_coupon(BOGOCoupon("17902", "PB", 0, 30));
    bool flag = true;
    while(flag) {
        int choice;
        menu(user);
        cin >> choice;
        int res;
        switch(choice) {
        case 1:
            cout << "Select restaurant\n"
                 << "\t1. Food Haven\n"
                 << "\t2. Pixel Bites\n"
                 << ">> ";
            cin >> res;
            if (res == 1) r1.display_menu();
            else if (res == 2) r2.display_menu();
            break;
        case 2:
            cout << "Select restaurant\n"
                 << "\t1. Food Haven\n"
                 << "\t2. Pixel Bites\n"
                 << ">> ";
            cin >> res;
            cout << "test\n";
            if (res == 1) get_receipt(user, r1);
            else if (res == 2) get_receipt(user, r2);
            break;
        case 3:
            cout << "Select restaurant\n"
                 << "\t1. Food Haven\n"
                 << "\t2. Pixel Bites\n"
                 << ">> ";
            cin >> res;
            int item;
            cout << "Enter item number: ";
            cin >> item;
            if (res == 1) r1.bill.push_back(item);
            else if (res == 2) r2.bill.push_back(item);
            break;
        case 4:
            flag = false;
            break;
        default:
            cout << "Invalid input" << endl;
        }
    }
    return 0;
}
