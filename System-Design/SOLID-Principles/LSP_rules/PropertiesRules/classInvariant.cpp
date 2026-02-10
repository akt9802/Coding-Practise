#include<iostream>
#include<string>

using namespace std;

// invariant means rules
// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.


//invariant cannt't be negative
class BankAccount{
    protected:
        double balance;
    public:
        BankAccount(double b){
            if(b < 0){
                throw invalid_argument("Balance can't be negative");
            }
            this->balance = b;
        }
        virtual void withdraw(double amount){
            if(balance-amount < 0){
                throw runtime_error("Insufficient funds");
            }
            balance -= amount;
            cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
        }
};


// brake invariant should not be followed 
class CheatAccount : public BankAccount {
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        balance -= amount; // LSP break! Negative balance allowed
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);
}