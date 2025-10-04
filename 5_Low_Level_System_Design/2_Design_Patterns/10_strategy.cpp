#include <iostream>
using namespace std;

// Strategy interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete strategies
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card\n";
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal\n";
    }
};

// Context
class PaymentContext {
private:
    PaymentStrategy* strategy;  // Has a strategy
public:
    PaymentContext(PaymentStrategy* s) : strategy(s) {}
    void setStrategy(PaymentStrategy* s) { strategy = s; }
    void pay(int amount) { strategy->pay(amount); }
};

int main() {
    CreditCardPayment cc;
    PayPalPayment pp;

    PaymentContext payment(&cc);
    payment.pay(100);   // Uses Credit Card

    payment.setStrategy(&pp);
    payment.pay(200);   // Switches to PayPal
}
