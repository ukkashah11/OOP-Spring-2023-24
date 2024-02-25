#include<iostream>
#include <vector>
using namespace std;
const int now = 8;
class Resteraunt{
    private:
    string resteraunt_name, location, resteraunt_code;
    vector<string> menu_list,valid_coupon_codes_list;
    vector<float> price_list;
    vector<int>bill;
    float total;
    static int coupons_redeemed_count;
    public:
    void display_menu(){
        cout<<"\tMENU"<<endl;
        for(int i=0;i<menu_list.size();i++){
        cout<<"["<<i+1<<"]: "<<menu_list[i]<<" -> $"<<price_list[i]<<endl;
        }
    }
    void generate_bill() {
        for (int i : bill) {
            cout << "[" << i+1 << "]: "<<menu_list[i]<<" -> $"<<price_list[i]<<endl;
            total += price_list[i];
        }
        cout<<"Total: $"<<total<<endl;
    }
    void apply_discount(){

    }
};
class BOGOCoupon{
    public:
    string coupon_code, resteraunt_code;
    int valid_from, valid_until;
    BOGOCoupon(string c_code, string res_code, int from, int until): coupon_code(c_code), resteraunt_code(res_code), valid_from(from), valid_until(until){}
    bool is_valid(string res_code){
        return (res_code != resteraunt_code && now>=valid_from && now<=valid_until) ? false : true;
    }
};
class User{
    public:
    string name, mobile_num;
    int age;
    vector<BOGOCoupon> coupons_list, redeemed_coupons_list;
    void Accumulate_coupon(BOGOCoupon coupon){
        coupons_list.push_back(coupon);
        cout<<"Coupon added to user list"<<endl;
    }
    // bool Has_valid_coupon(BOGOCoupon coupon){
    //     coupon.is_valid()
    // }
};
