/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include<iostream>
using namespace std;
class LoanHelper{
    const float interest_rate;
    float loan_amount;
    int loan_term; //num of months the loan is applicable for
    public:
    LoanHelper(float rate, float loanAmount = 0.0f, int term = 0) : interest_rate(rate), loan_amount(loanAmount), loan_term(term) {}
    void setLoan(const float loan_amount) {
        this->loan_amount = loan_amount;
    }
    void setLoanTerm(const int loan_term) {
        this->loan_term = loan_term;
    }
    float getInterestRate() const {
        return interest_rate;
    }
    float getLoanAmount() const {
        return loan_amount;
    }
    int getLoanTerm() const {
        return loan_term;
    }
    float calcRepayment(const float rate, const float amount, const int months){
            float repay = amount/months;
            return repay +(repay*rate);
    }
};
int main(){
    LoanHelper l(0.2, 12000, 8);
    cout<<"You have to pay $"<<l.calcRepayment(l.getInterestRate(), l.getLoanAmount(), l.getLoanTerm())<<" every month for "<<l.getLoanTerm()<<" months to repay your loan"<<endl;
    return 0;
}

