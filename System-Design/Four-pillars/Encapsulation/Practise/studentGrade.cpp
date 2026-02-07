#include<iostream>
#include<string>
using namespace std;

class Student{
    private :
        string name="No name set yet !!";
        int marks = 0;

    public:
        void setMarks(int m){
            if(m<0 || m>100){
                cout<<"The marks you are entering for this student is not Possible !!"<<endl;
                return ;
            }
            this->marks = m;
            cout<<"Marks updated successfully for "<<this->name<<endl;
        }

        int getMarks() const{
            return this->marks;
        }

        void setName(string n){
            this->name = n;
            cout<<"Name updated successfully !!"<<endl;
        }

        string getName() const{
            return this->name;
        }

        string getGrade() const{
            if(this->marks > 90){
                return "A+";
            }
            else if(this->marks > 80){
                return "B+";
            }
            else{
                return "C+";
            }
        }

        // destructor
        ~Student(){};  
};

int main(){

    Student* s1 = new Student();
    cout<<s1->getName()<<endl;
    s1->setName("aman");
    cout<<s1->getName()<<endl;

    cout<<s1->getMarks()<<endl;
    s1->setMarks(183);
    s1->setMarks(83);    
    cout<<s1->getMarks()<<endl;
    cout<<s1->getGrade()<<endl;

    delete s1;
    return 0;
}