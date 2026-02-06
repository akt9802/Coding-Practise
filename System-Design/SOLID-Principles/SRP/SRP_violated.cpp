// SRP stands for single responsibility principle

#include<iostream>
#include<string>

using namespace std;

class Product{
    public:
        string name;
        double price;
    
    Product(string name,double price){
        this->name = name;
        this->price = price;    
    }
}

class ShoppingCart{
    private :
        vector<Product*> products;
    
    public:
        void addProduct(Product* p){
            products.push_back(p);
        }

        // & we are passing by refference here in this 
        // and by using this const you are not allowed to push into this product
        // because here we are passing this by refference so basically we are giving the product(which is private) and if we donot use const then anyone can direclty push_back into the product array

        const vector<Product*>& getProducts(){
            return products;
        }

        // Function 1 : Calculating the Total price in the cart
        double calculateTotal(){
            double total = 0;
            for(auto it:products){
                total += it->price;
            }
            return total;
        }

        // Function 2 : Printing invoice 
        void printInvoice(){
            cout<<"Shopping Car invoice !!"<<endl;
            for(auto it:products){
                cout<<it->name<<" "<<it->price<<endl;
            }
            cout<<"Total Price : "<<calculateTotal()<<endl;
        }

        void saveToDatabase(){
            cout<<"Saving shopping cart to the database...."<<endl; 
        }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",5000));
    cart->addProduct(new Product("Mouse",2000));

    cart->printInvoice();
    cart->saveToDatabase();
    return 0;
}