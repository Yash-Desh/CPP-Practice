#include <iostream> 
#include <atomic>
#include <span>
#include <thread>
#include <vector>
using namespace std;

void peer1_do_work(const span<uint8_t> input, vector<uint8_t> output); 
void peer2_do_work(const span<uint8_t> input, vector<uint8_t> output);

int peer1_loop(atomic_bool* running) {
    std::vector<uint8_t> input;
    
    while(*running) {
        std::vector<uint8_t>output; 
        peer1_do_work(input, output);
        
        // TODO: communicate with peer
        
    }
    return 0;
}

int peer2_loop(atomic_bool* running) {
    std::vector<uint8_t> input;
    
    while (*running) {
        std:: vector<uint8_t> output;
        peer2_do_work(input, output);
        
        // TODO: send/recv packet

    }
    return 0;
}

int main() {
    atomic_bool running;
    thread t1(peer1_loop, &running); 
    thread t2(peer2_loop, &running);
    
    // ...
}