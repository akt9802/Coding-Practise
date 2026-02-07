#include<iostream>
#include<string>

using namespace std;


// this name and age can't be accessed inside the child class you can now access because you are using getter and setter
// instead of this private use protected because protected variable can be accessed inside the child class

class Person{
    private :
        string name;
        int age;
    
    public :
        void setPerson(string n,int a){
            this->name = n;
            this->age = a;
        }
        void displayPerson(){
            cout<<"Name of Person is "<<this->name<<" and age is "<<this->age<<endl; 
        }

        ~Person(){}
};

class Student : public Person{
    private :
        int rollNumber;
        int marks;

    public:
        void setStudent(int rollNumber,int marks){
            this->rollNumber = rollNumber;
            this->marks = marks;
        }
        
        void displayStudent(){
            cout<<"Roll Number : "<< this->rollNumber << " Marks : "<<this->marks<<endl;
        }

        ~Student(){}
};

int main(){
    Student* s1 = new Student();
    s1->setPerson("Rahul",15);
    s1->displayPerson();

    s1->setStudent(220103015,89);
    s1->displayStudent();

    delete s1;
    return 0;
    
}