// Author: Yash Deshpande
// Date  : 30-09-2026
// Tutor : Claude Opus 5

#include <iostream>
#include <atomic>
#include <semaphore>
#include <span>
#include <thread>
#include <vector>
using namespace std;

void peer1_do_work(const span<uint8_t> input, vector<uint8_t>& output);
void peer2_do_work(const span<uint8_t> input, vector<uint8_t>& output);

// global buffer, single slot, shared by both peers
vector<uint8_t> buffer;

// sem1 == 1 means the slot is peer1's to read, sem2 == 1 means it is peer2's.
// Strict alternation, so only one peer ever touches the buffer: no mutex needed.
// peer1 owns the slot first, peer2 waits
std::binary_semaphore sem1{1};
std::binary_semaphore sem2{0};

int peer1_loop(atomic_bool* running) {
    std::vector<uint8_t> input;

    while(*running) {
        std::vector<uint8_t>output;

        // take lock -> global buffer is shared state
        // if unsuccessful put me to sleep.
        sem1.acquire();
        // copy / move buffer contents to input
        input = std::move(buffer);
        buffer.clear();

        peer1_do_work(input, output);

        // copy contents of output to buffer.
        buffer = std::move(output);

        // wake peer2 -> buffer
        sem2.release();
        
    }
    return 0;
}

int peer2_loop(atomic_bool* running) {
    std::vector<uint8_t> input;

    while (*running) {
        std:: vector<uint8_t> output;

        // mirror of peer1: wait for our turn on the slot
        sem2.acquire();
        input = std::move(buffer);
        buffer.clear();

        peer2_do_work(input, output);

        // publish our packet, then hand the slot back to peer1
        buffer = std::move(output);
        sem1.release();

    }
    return 0;
}

int main() {
    atomic_bool running;
    thread t1(peer1_loop, &running);
    thread t2(peer2_loop, &running);

    // ...
}