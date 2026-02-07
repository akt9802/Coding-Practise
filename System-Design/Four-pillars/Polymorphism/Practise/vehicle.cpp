#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void fuelType() = 0;
    virtual ~Vehicle() {}
};

class PetrolCar : public Vehicle {
public:
    void start() override {
        cout << "Petrol Car starts with engine ignition\n";
    }

    void stop() override {
        cout << "Petrol Car engine stopped\n";
    }

    void fuelType() override {
        cout << "Fuel Type: Petrol\n";
    }
};

class ElectricCar : public Vehicle {
public:
    void start() override {
        cout << "Electric Car starts silently\n";
    }

    void stop() override {
        cout << "Electric Car powered off\n";
    }

    void fuelType() override {
        cout << "Fuel Type: Electricity\n";
    }
};

class HybridCar : public Vehicle {
public:
    void start() override {
        cout << "Hybrid Car starts using electric + petrol\n";
    }

    void stop() override {
        cout << "Hybrid Car engine stopped\n";
    }

    void fuelType() override {
        cout << "Fuel Type: Petrol + Electricity\n";
    }
};

int main() {
    vector<Vehicle*> vehicles;

    vehicles.push_back(new PetrolCar());
    vehicles.push_back(new ElectricCar());
    vehicles.push_back(new HybridCar());

    for (Vehicle* v : vehicles) {
        v->start();
        v->fuelType();
        v->stop();
        cout << "-------------------\n";
    }

    // clean up memory
    for (Vehicle* v : vehicles) {
        delete v;
    }

    return 0;
}
