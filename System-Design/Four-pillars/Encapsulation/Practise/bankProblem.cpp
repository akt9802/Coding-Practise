#include<iostream>
#include<string>

using namespace std;

class BankAccount{
    private:
        string accountHolderName;
        double balance=0;

    public:
        void deposit(double amount){
            if(amount <= 0){
                cout<<"Amount should be greater than 0 for deposit !!"<<endl;
                return ;
            }
            balance += amount;
            cout<<amount<<" Added successfully !!"<<endl;
        }

        void withdraw(double amount){
            if(amount<=0){
                cout<<"You cant withdraw as you have zero balance !!"<<endl;
            }
            
            if(amount > balance){
                cout<<"Not enough balance to withdraw this amount !!"<<endl;
                return ;
            }
            balance -= amount;
            cout<<amount<<" Deducted from the balance !!"<<endl;
        }

        void getBalance(){
            cout<<"Your current Balance is "<<balance<<endl;
        }
        // double getBalance() const {
        //     return balance;
        // }


        void setName(string name){
            this->accountHolderName = name;
            cout<<"Name changed successfully !!"<<endl;
        }
        
        void getName(){
            cout<<"Name is "<<accountHolderName<<endl;
        }
        
        ~BankAccount(){};
};

int main(){
    BankAccount* kotak = new BankAccount();
    kotak->setName("Aman");
    kotak->getName();
    kotak->withdraw(200);
    kotak->deposit(500);
    kotak->withdraw(200);
    kotak->getBalance();

    delete kotak;
    return 0;
}