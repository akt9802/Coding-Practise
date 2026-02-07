#include<iostream>
#include<string>
using namespace std;

class SmartDevice{
    public :
        // pure virtual function
        virtual void turnOn() = 0 ;
        virtual void turnOf() = 0;
        virtual void status() = 0;

        virtual ~SmartDevice(){};
};

class SmartLight: public SmartDevice{
    public :
        bool isOn;
    
        SmartLight(){
            isOn = false;
        }

        void turnOn(){
            isOn = true;
            cout<<"Light is turned ON !!"<<endl;
        }
        void turnOf(){
            isOn = false;
            cout<<"Light is turned OF !!"<<endl;
        }

        void status(){
            if(isOn == true){
                cout<<"Current Status of light is ON !!"<<endl;
            }
            else{
                cout<<"Current Status of light is OF !!"<<endl;
            }
        }
        
        // donot forgot to call destructor
        ~SmartLight(){};
};

int main(){
    SmartDevice* light = new SmartLight();
    light->status();
    light->turnOn();
    light->status();
    light->turnOf();

    // becaue we allocate heap memory so we have to do deallocation manually 
    delete light; // this will trigger destructor of smart light
    return 0;
}