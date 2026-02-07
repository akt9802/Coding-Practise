#include<iostream>
#include<string>

using namespace std;

// abstract class
class Payment{
    public:
        // abstract class should be pure interface
        virtual void pay(double amount) = 0;
        virtual void refund(double amount) = 0;
};

class UPIPayment : public Payment{
    public :
        // double amount;
        // no need of defining this becasue we are not creating a class which will intialized with payment, payment is something which we will pass as parameter in the class methods

        void pay(double amount) override{
            cout<<"You paid : "<<amount<<" using UPI"<<endl;
        }
        void refund(double amount) override{
            cout<<"Refunded amount : "<<amount<<" to UPI"<<endl;
        }
};

class CardPayment : public Payment{
    public:
        void pay(double amount) override{
            cout<<"You paid : "<<amount<<" using Card"<<endl;
        }
        void refund(double amount) override{
            cout<<"Refunded amount : "<<amount<<" to Card"<<endl;
        }
};
int main(){
    CardPayment* card = new CardPayment();
    card->pay(500);
    card->refund(200);

    UPIPayment* upi = new UPIPayment();
    upi->pay(300);
    upi->refund(100);

    delete card;
    delete upi;
    return 0;
}