// Author : Yash Deshpande
// Date   : 27-09-2025
// Tutor  : Keerti Purswani : https://youtu.be/tv54FY48Vio?si=9Bg-09FAKkjKN5CB

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


// Any modification/additions of extra vehicles will be done in the factory
// and not in the client code.
class VehicleFactory {
    public:
        static Vehicle* getVehicle(string vehicleType) {
            Vehicle* vehicle;
            if(vehicleType == "car") {
                vehicle = new Car;
            }
            else if(vehicleType == "bus") {
                vehicle = new Bus;
            }
            else {
                cout<<"Invalid Input, Enter either car or bus\n";
            }
            return vehicle;
        }
};

int main() {
    string vehicleType; 
    cin>>vehicleType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();

    return 0;
}
