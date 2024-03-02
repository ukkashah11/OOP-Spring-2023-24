/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include<iostream>
using namespace std;
class BankAccount{
    string accountNumber, accountHolderName;
    float balance;
    public:
    BankAccount(string acc_num, string name, float acc_balance):accountNumber(acc_num), accountHolderName(name), balance(acc_balance){}
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"\n$"<<amount<<" deposited"<<endl;
        }
    }
    void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance-=amount;
            cout<<"\n$"<<amount<<" withdrawn"<<endl;
        }
    }
    void display(){
        cout << "\nAccount Number: "<<accountNumber<<endl;
        cout << "Account Holder: "<<accountHolderName<<endl;
        cout << "Balance: $"<<balance<<endl;
    }
};
int main(){
    BankAccount accounts[]={BankAccount("123456789", "Syed Ukkashah", 15000), BankAccount("0987654321", "Ahmed Shah", 20000), BankAccount("1765349703", "Champagne Papi", 100000)};
    for(BankAccount b:accounts){
         b.display();
         b.deposit(500.0);
         b.display();
         b.withdraw(200.0);
         b.display();
    }
}