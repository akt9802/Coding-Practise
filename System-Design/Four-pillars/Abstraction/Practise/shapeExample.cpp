#include<iostream>
#include<string>

using namespace std;

class Shape{
    public:
        virtual double area() = 0;
        virtual void display() = 0;

        virtual ~Shape() {}

};

class Rectangle : public Shape{
    public :
        int l;
        int h;

        Rectangle(int l,int h){
            this->l = l;
            this->h = h;
        }

        double area() override{
            double a = (this->l)*(this->h);
            return a;
        }

        void display() override{
            cout<<"Area of rectangle is : "<<area()<<endl;
        }
};

class Circle : public Shape{
    public :
        int r;

        Circle(int r){
            this->r = r;
        }

        double area() override{
            double a = 3.14*(this->r)*(this->r);
            return a;
        }

        void display() override{
            cout<<"Area of Cicle is : "<<area()<<endl;
        }
};


int main(){

    Shape* pointer1 = new Rectangle(2,3);
    Shape* pointer2 = new Circle(2);

    pointer1->area();
    pointer1->display();

    pointer2->area();
    pointer2->display();

    delete pointer1;
    delete pointer2;

    return 0;
 
}