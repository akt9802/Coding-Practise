#include<iostream>
#include<string>

using namespace std;

// Product class representing any item in the eCommerce
class Product{
    public:
        string name;
        double price;

        Product(string name,double price){
            this->name = name;
            this->price = price;
        }
};

// shoppingCart : only responsible for Cart related business logic
class ShoppingCart{
    private:
        vector<Product*> products;
    
    public :
        void addProduct(Product* product){
            products.push_back(p);
        }

        const vector<Product*> getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto it:products){
                total += products->price;
            }
            return total;
        }
};

class ShoppingCartPrinter{
    private :
        ShoppingCart* cart;
    
    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout<<"Shipping Cart details !!"<<endl;
            for(auto it:cart->getProducts()){
                cout<< it->name << " "<< it->price<<endl;
            }
            cout<<"Total : Rs "<< cart->calculateTotal() <<endl;
        }
};

// shopping cart storage : only responsible for saving to cart to DB
class ShoppingCartStorage{
    private:
        shoppingCart* cart;
    public:
        ShoppingCartStorage(shoppingCart* cart){
            this->cart = cart;
        }
        void saveToDatabase(){
            cout<<"Saving shopping cart to databse...."<<endl;
        }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop",5000));
    cart->addProduct(new Product("Mouse",2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();

    return 0;

}