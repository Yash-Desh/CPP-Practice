// Type your code here, or load an example.
#include <thread>
#include <iostream>
#include <mutex>
#include <semaphore>
#include <condition_variable>
#include <bits/stdc++.h>

using namespace std;

void peer1_do_work(const span<uint8_t> input, vector<uint8_t> output);
void peer2_do_work(const span<uint8_t> input, vector<uint8_t> output);

std::binary_semaphore sem_peer1{1};
std::binary_semaphore sem_peer2{0};
std::vector<uint8_t>* inputPtr = nullptr;

int peer1_loop(atomic_bool *running)
{
    std::vector<uint8_t> input;

    sem_peer1.acquire();
    while (*running)
    {
        if (inputPtr != nullptr)
        {
            memcpy(&input, &inputPtr, sizeof(*inputPtr));
            // use std::copy() or copy in a for loop
        }
        std::vector<uint8_t> output;
        peer1_do_work(input, output);

        inputPtr = &output;
        sem_peer2.release();
        sem_peer1.acquire();

    }
}

int peer1_loop(atomic_bool *running)
{
    std::vector<uint8_t> input;

    sem_peer2.acquire();
    while (*running)
    {
        if (inputPtr != nullptr)
        {
            memcpy(&input, &inputPtr, sizeof(*inputPtr));
            // use std::copy() or copy in a for loop
        }
        std::vector<uint8_t> output;
        peer1_do_work(input, output);

        inputPtr = &output;
        sem_peer1.release();
        sem_peer2.acquire();

    }
}

std::condition_variable cv;
std::mutex m;
std::vector<uint8_t>* inputPtr = nullptr;
bool turn = 0;

int peer1_loop(atomic_bool *running)
{
    std::vector<uint8_t> input;

    std::unique_lock ul(m);
    cv.wait(ul, ()^[turn == 0]);
    while (*running)
    {
        if (inputPtr != nullptr)
        {
            memcpy(&input, &inputPtr, sizeof(*inputPtr));
            // use std::copy() or copy in a for loop
        }
        std::vector<uint8_t> output;
        peer1_do_work(input, output);

        inputPtr = &output;
        turn = 1; // update it to other peers turn
        ul.unlock(); 
        cv.signal();
        cv.wait(ul, ()^[turn == 0]);
    }
}


int peer2_loop(atomic_bool *running)
{
    std::vector<uint8_t> input;

    std::unique_lock ul(m);
    cv.wait(ul, ()^[turn == 1]);
    while (*running)
    {
        if (inputPtr != nullptr)
        {
            memcpy(&input, &inputPtr, sizeof(*inputPtr));
            // use std::copy() or copy in a for loop
        }
        std::vector<uint8_t> output;
        peer2_do_work(input, output);

        inputPtr = &output;
        turn = 0; // update it to other peers turn
        ul.unlock(); 
        cv.signal();
        cv.wait(ul, ()^[turn == 1]);
    }
}
