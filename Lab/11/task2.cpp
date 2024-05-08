#include "iostream"
using namespace std;
class Account{
    protected:
    double balance;
    unsigned int accountNum;
    float interest;
    public:
    Account(double b, unsigned int num): balance(b), accountNum(num){}
    void virtual deposit(double amount) = 0;
    void virtual withdraw(double amount) = 0;
    float virtual calculateInterest() = 0;
    int getAccountNumber()const{return accountNum;}
    double getBalance() const{return balance;}
};
class SavingsAccount: public Account{
    double interestRate;
    public:
    SavingsAccount(double b, unsigned int num, double ir):Account(b,num), interestRate(ir){}
    void deposit(double amount)
    {
        balance+=amount;
        cout<<amount<<" deposited"<<endl;
    }
    void withdraw(double amount)
    {
        if(amount>balance) cout<<"Insufficient funds"<<endl;
        else
        {
            balance-=amount;
            cout<<amount<<" withdrawn"<<endl;

        } 
    }
    float calculateInterest(){return balance*1.2;}
};
class CurrentAccount: public Account{
    double overdraftLimit;
    public:
    CurrentAccount(double b, unsigned int num, double odlimit):Account(b,num), overdraftLimit(odlimit){}
    void deposit(double amount)
    {
        balance+=amount;
        cout<<amount<<" deposited"<<endl;
    }
    void withdraw(double amount)
    {
        if(amount>balance+overdraftLimit) cout<<"Insufficient funds"<<endl;
        else
        {
            balance-=amount;
            cout<<amount<<" withdrawn"<<endl;

        } 
    }
    float calculateInterest(){return 0.f;}
};

