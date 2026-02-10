#include<iostream>
#include<string>

using namespace std;

class Animal{
    // some common animal methods
};

class Dog: public Animal{
    // additional dog methods sepecific to dogs
};

class Parent{
    public:
        virtual Animal* getAnimal(){
            cout<<"Child returning dog instance : "<<endl;
            return new Animal();
        }
};

class Child : public Parent{
    public :
        // this overrided function should return this Animal* just like his parent class method
        Animal* getAnimal() override{
            cout << "Child : Returning Dog instance" << std::endl;
            return new Dog();
        }
};

class Client{
    private:
        Parent* p;
    
    public:
        Client(Parent* p){
            this->p = p;
        }
        void takeAnimal(){
            p->getAnimal();
        }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);
    //Client * client = new Client(parent);
    client->takeAnimal();

    return 0;
}