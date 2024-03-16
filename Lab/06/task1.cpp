#include<iostream>
using namespace std;
class BankAccount{
    int accountId, numTransactions;
    int* transactionHistory;
    double balance;
    public:
    BankAccount(int accountId, double balance, int* history, int numTransactions){
        this->accountId = accountId;
        this->balance = balance;
        this->numTransactions = numTransactions;
        transactionHistory = new int[numTransactions];
        transactionHistory = history;
    }
    BankAccount(const BankAccount &obj){
        accountId = obj.accountId;
        balance = obj.balance;
        numTransactions = obj.numTransactions;
        transactionHistory = new int[numTransactions];
        for(int i=0; i<obj.numTransactions; i++){
            transactionHistory[i] = obj.transactionHistory[i];
        }
    }
    void updatetransactionHistory(){
        int choice;
        double amount;
        cout<<"Press 1 to withdraw, 2 to deposit: ";
        cin>> choice;
        switch(choice){
            case 1:
            cout<<"Enter amount to withdraw: ";
            cin>>amount;
            if(amount<=balance){
                balance-=amount;
                cout<<"$"<<amount<<" withdrawn"<<endl;
                transactionHistory[numTransactions++] = -amount;
            }
            else{
                cout<<"Insufficient balance"<<endl;
            }
            break;
            case 2:
            cout<<"Enter amount to deposit: ";
            cin>>amount;
            if(amount>0){
                balance+=amount;
                cout<<"$"<<amount<<" deposited"<<endl;
                transactionHistory[numTransactions++] = amount;
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
            break;
            defualt:cout<<"Invalid input"<<endl;
        }
    }
    void display(){
        cout<<"Account ID: "<<accountId<<endl;
        cout<<"Account Balance: $"<<balance<<endl;
        cout<<"Transaction History: \n";
        for(int i=0; i<numTransactions; i++){
            if(transactionHistory[i]>0){
                cout<<"$"<<transactionHistory[i]<<" deposited"<<endl;
            }
            if(transactionHistory[i]<0){
                cout<<"$"<<abs(transactionHistory[i])<<" withdrawn"<<endl;
            }
        }
    }
    ~BankAccount(){
         delete[] transactionHistory;
    }
};
int main(){
    // Initial transaction history
    int transactions[] = {100, -50, 200, -100};
    int numTransactions = sizeof(transactions) / sizeof(transactions[0]);
    // Create a BankAccount object
    BankAccount account1(1, 500.0, transactions, numTransactions);
    // Create a copy of the original account
    BankAccount accountCopy = account1;
    // Display details of both the original and copied accounts
    cout << "Original Account Details:" << endl;
    account1.display();
    cout << "\nCopied Account Details:" << endl;
    accountCopy.display();
    account1.updatetransactionHistory();
    // Display the original account details again to see the changes
    cout << "\nOriginal Account Details after updating transaction history:" << endl;
    account1.display();

    return 0;
}