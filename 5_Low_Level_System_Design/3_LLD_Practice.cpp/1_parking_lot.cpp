// Author : Yash Deshpande
// Date   : 27-09-2025
// Tutor  : LeetCode

#include <iostream>
#include <string>
#include <map>
#include <chrono>
using namespace std;

/*
Requirements:

The parking lot system should be able to park bikes, cars, and trucks vehicles.
The system should be able to keep track of the time a vehicle is parked.
The system should be able to calculate the cost of parking of each type of vehicles.
The system should be able to calculate number of hours a vehicles has been parked.
The system should be able to remove a vehicle from the parking spots.
The system will work on first come first serve basis.

*/ 

enum class VehicleType {
    kBike,
    kCar,
    kTruck
};

// *********************Abstract Class for payment *********************
class Payment{
public:
    virtual double CalculateCost(double hours) = 0; 
};

class BikePayment : public Payment {
public:
    double CalculateCost(double hours) { return hours * 10; }
};

class CarPayment : public Payment {
public: 
    double CalculateCost(double hours) { return hours * 20; }
};

class TruckPayment : public Payment {
public: 
    double CalculateCost(double hours) { return hours * 50; }
};


// ********************* Abstract Class for vehicle *********************
class Vehicle {
protected:
    string numberplate;
    Payment *cost;
    int VehicleType;
    std::chrono::time_point<std::chrono::system_clock> parkTime;

public:

    virtual enum VehicleType GetType() = 0;

    virtual double CalculateCost(double hours) {
        return cost->CalculateCost(hours);
    } 

    string getNumberPlate() {
        return numberplate;
    }

    void setStartTime() {

    }

    std::chrono::time_point<std::chrono::system_clock> getStartTime() {
        return parkTime;
    }


};

class Bike : public Vehicle {
public:
    Bike(string NumberPlate) {
        numberplate = NumberPlate;
        cost = new BikePayment;
    }

    virtual enum VehicleType GetType(){
        return VehicleType::kBike;
    }
};


class ParkingLot {
private:
    int floors;
    int rows;
    int spotsPerRow;
    map<int, map<int, map<string, Vehicle *>>> grid;
public:

    // Constructor
    ParkingLot(int floors, int rows, int sportsPerRow) : floors(floors), rows(rows), spotsPerRow(sportsPerRow) { }

    bool park(Vehicle *vehicle, int floor, int row) {
        if(grid[floor][row].size() < spotsPerRow) {
            // Get Number Plate
            std::string numberPlate = vehicle->getNumberPlate();
            grid[floor][row][numberPlate] = vehicle;
            return true;
        }
        else {
            return false;
        }
    }
    bool leave(Vehicle* vehicle) {
        string numberPL = vehicle->getNumberPlate();
        for(int i=0; i<floors; i++) {
            for(int j = 0; j<rows; j++) {
                if(grid[i][j].find(numberPL) != grid[i][j].end()) {

                    double hours = CalculateParkingHours(vehicle);
                    double cost = vehicle->CalculateCost(hours);
                    grid[i][j].erase(numberPL);
                    cout << static_cast<int>(vehicle->GetType()) << " left successfully. Total cost: " << cost << endl;
                    return true;
                }
            }
        }
        // Vehicle Not Found
        return false;
    }
    double CalculateParkingHours(Vehicle* vehicle) {
        for (int i = 0; i < floors; i++) {
            for (int j = 0; j < rows; j++) {
                std::string numberPlate = vehicle->getNumberPlate();
                if (grid[i][j].find(numberPlate) != grid[i][j].end()) {
                    // Vehicle *ownerVehicle = spots[i][j][numberPlate];
                    // Get the current time
                    auto currentTime = std::chrono::system_clock::now();
                    auto parkTime = vehicle->getStartTime();
                    // auto duration = std::chrono::duration_cast<std::chrono::hours>(currentTime - parkTime);
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - parkTime);
                    return duration.count();
                }
            }
        }
        return 0;
    }
    int availableSpots(int floor);
};

int main() {
    return 0;
}