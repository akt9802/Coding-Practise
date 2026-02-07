#include <iostream>
#include <string>

using namespace std; 


// << abstract class >>
class Animal{
    public :
        virtual void makeSound() = 0;
    virtual ~Animal(){};
};

// Q: Why virtual destructor in base class?
// Because when deleting an object through a base class pointer, a virtual destructor ensures the derived class destructor is also called, preventing memory/resource leaks.

class Dog : public Animal{
    public :
        // override
        void  makeSound() override{
            cout<<"Dogs bark !!"<<endl;
        }
};

class Cat : public Animal{
    public:
        // override
        void makeSound() override{
            cout<<"Cat meow !!"<<endl;
        }
};

int main(){
    Animal* a = new Dog();
    Animal* b = new Cat();

    a->makeSound();
    b->makeSound();

    delete a;
    delete b;
    return 0;

}
