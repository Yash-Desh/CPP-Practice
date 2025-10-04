// Author : Yash Deshpande
// Date   : 27-09-2025
// Tutor  : Keerti Purswani: https://youtu.be/tv54FY48Vio?si=9Bg-09FAKkjKN5CB

// Problem : Any modifications required will have to be done by the client as well. 

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    public:
        virtual void createVehicle() = 0;
};

class Car : public Vehicle {
    public:
        void createVehicle() {
            cout<<"Creating Car."<<endl;
        }
};

class Bus : public Vehicle {
    public:
        void createVehicle() {
            cout<<"Creating Bus."<<endl;
        }
};

int main() {
    string vehicleType; 
    cin>>vehicleType;

    Vehicle *vehicle;
    if(vehicleType == "car") {
        vehicle = new Car;
    }
    else if(vehicleType == "bus") {
        vehicle = new Bus;
    }
    else {
        cout<<"Invalid Input, Enter either car or bus\n";
    }
    vehicle->createVehicle();
    return 0;
}
