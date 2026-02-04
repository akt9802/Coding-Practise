// #include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

// Car is abstract base class
// think of it as blueprint of a blueprint 
// virtual means this function can be overridden by child class(like tesla/ford)
// = 0 makes the function purely virtual
// if we change pure virtual function to regular virtual function With = 0, the class is Abstract (a blueprint). You aren't allowed to create a Car object. With { }, the class is Concrete
class Car{
    public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    // destructor 
    virtual ~Car() {}
};


/*
1. This is a Concrete class (A class that provide implementation details of an abstract class).
Now anyone can make an Object of 'SportsCar' and can assign it to 'Car' (Parent class) pointer 
(See main method for this)

2. In our real world example of Car, as you cannot have a real car by just having its body only
(all these buttons or steering wheel). You need to have the actual implementation of 'What' happens
when we press these buttons. 'SportsCar' class denotes that actual implementation. 

3. Therefore, to denote a real world car in programming we created 2 classes.
One to denote all the user-interface like pedals, buttons, steering wheels etc ('Car' class).And,
Another one to denote the actual car with all the implementations of these buttons (SportsCar' class).
*/

class SportsCar : public Car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        SportsCar(string b,string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout<< brand<<" "<<model<<" : Engine starts with a roar !"<<endl;
        }

        void shiftGear(int gear){
            if(isEngineOn==false){
                cout<<brand<<" "<<model<<" Engine is off so can't shift Gear !"<<endl;
                return ;
            }
            currentGear = gear;
            cout<<brand<<" "<<model<<" Shifted to gear "<<currentGear<<endl;
        }
        void accelerate(){
            if(isEngineOn==false){
                cout<<brand<<" "<<model<<" Engine is off so can't accelerate !"<<endl;
                return ;
            }
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<endl;
        }
        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0){
                currentSpeed = 0;
            }
            cout<<brand<<" "<<model<<" : Break applided, Now speed is "<<currentSpeed<<endl;
        }
        
        void stopEngine(){
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Engine is turned off !!";
        }
};

int main(){
    // this is code which helps us to understand what is abstraction 
    Car* myCar = new SportsCar("Ford","Mustand");

    // In professional coding and interviews, Car* is preferred. It follows the "Dependency Inversion Principle," which basically says: Depend on abstractions (the blueprint), not on concretions (the specific model). It makes your code "future-proof." If you add a Truck class tomorrow, you don't have to rewrite your main function; the Car* pointer will just work with it automatically!

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;    

    return 0;
}