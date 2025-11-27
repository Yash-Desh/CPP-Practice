// Author: Yash Deshpsnde
// Date  : 23-11-2025
// Tutor : 

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <semaphore>
#include <functional>
using namespace std;

/**
 * Traffic Light Controller for managing intersection crossing
 * Ensures cars from different roads don't cross simultaneously
 */
class TrafficLight {
private:
    // Tracks which road currently has the green light (1 for road A, 2 for road B)
    int currentGreenRoad;
    // Mutex for thread-safe synchronization
    std::mutex mtx;

public:
    /**
     * Constructor initializes the traffic light system
     * Default: Road 1 (road A) has the green light initially
     */
    TrafficLight() {
        currentGreenRoad = 1;
    }

    /**
     * Handles car arrival at the intersection
     * Ensures thread-safe operation using mutex lock
     *
     * @param carId      Unique identifier of the arriving car
     * @param roadId     ID of the road the car is on (1 for road A, 2 for road B)
     * @param direction  Direction the car is traveling
     * @param turnGreen  Function to switch the traffic light to green for current road
     * @param crossCar   Function to allow the car to cross the intersection
     */
    void carArrived(
            int carId,                          // ID of the car
            int roadId,                         // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
            int direction,                      // Direction of the car
            std::function<void()> turnGreen,    // Use turnGreen() to turn light to green on current road
            std::function<void()> crossCar      // Use crossCar() to make car cross the intersection
    ) {
        // Lock the mutex for thread-safe access
        std::lock_guard<std::mutex> lock(mtx);

        // If car's road doesn't have green light, switch the light
        if (roadId != currentGreenRoad) {
            turnGreen();
            currentGreenRoad = roadId;
        }

        // Allow the car to cross the intersection
        crossCar();
    }
};
int main() {
    return 0;
}