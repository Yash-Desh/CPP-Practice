#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class FizzBuzz {
private:
    int n;
    int i;   // shared variable to store current token
    std::condition_variable cv;
    std::mutex m;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i <= n){
            std::unique_lock<std::mutex> lock(m);
            while((i<=n) &&  !((i%3) == 0 && (i%5) != 0))
                cv.wait(lock);
            if(i <= n){
                printFizz();
                i++;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i<=n){
            std::unique_lock<std::mutex> lock(m);
            while((i<=n) &&  !((i%3) != 0 && (i%5) == 0))
                cv.wait(lock);
            if(i<=n){
                printBuzz();
                i++;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i<=n){
            std::unique_lock<std::mutex> lock(m);
            while((i<=n) &&  !((i%3 == 0) && (i%5) == 0))
                cv.wait(lock);
            if(i<=n){
                printFizzBuzz();
                i++;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i<=n){
            std::unique_lock<std::mutex> lock(m);
            while((i<=n) &&  !((i%3) != 0 && (i%5) != 0))
                cv.wait(lock);
            if(i <= n){
                printNumber(i);
                i++;
            }
            cv.notify_all();
        }
    }
};


int main()
{
    return 0;
}