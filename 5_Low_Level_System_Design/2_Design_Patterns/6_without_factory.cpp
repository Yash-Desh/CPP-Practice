// Author : Yash Deshpande
// Date   : 27-09-2025
// Tutor  : https://www.geeksforgeeks.org/system-design/factory-method-for-designing-pattern/

#include <iostream>
using namespace std;

// ################
// Library classes
// ################
class Vehicle {
public:
    virtual void printVehicle() = 0; // Pure virtual function
};

class TwoWheeler : public Vehicle {
public:
    void printVehicle() override {
        cout << "I am two wheeler" << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void printVehicle() override {
        cout << "I am four wheeler" << endl;
    }
};


// ########################
// Client (or user) class
// ########################
class Client {
private:
    Vehicle* pVehicle;

public:
    Client(int type) {
        if (type == 1) {
            pVehicle = new TwoWheeler();
        } else if (type == 2) {
            pVehicle = new FourWheeler();
        } else {
            pVehicle = nullptr;
        }
    }

    void cleanup() {
        if (pVehicle != nullptr) {
            delete pVehicle;
            pVehicle = nullptr;
        }
    }

    Vehicle* getVehicle() {
        return pVehicle;
    }
};

// ################
// Driver program
// ################
int main() {
    Client pClient(1);
    Vehicle* pVehicle = pClient.getVehicle();
    if (pVehicle != nullptr) {
        pVehicle->printVehicle();
    }
    pClient.cleanup();
    return 0;
}

/*
Issues with the Current Design
--> Tight coupling: Client depends directly on product classes.
--> Violation of SRP: Client handles both product creation and usage.
--> Hard to extend: Adding a new vehicle requires modifying the client.
*/