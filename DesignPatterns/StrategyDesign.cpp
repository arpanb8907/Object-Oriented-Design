#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class PaymentStrategy
{
public:
    virtual void pay(const string& amount) = 0;

    virtual ~PaymentStrategy() {}
};

class CreditCardPayment : public PaymentStrategy
{
public:
    void pay(const string& amount)
    {
        cout <<amount<<" "<<"paid successfully by CreditCard"<<endl;
    }
};

class DebitCardPayment : public PaymentStrategy
{
public:
    void pay(const string& amount)
    {
        cout <<amount<<" "<<"paid successfully by DebitCard"<<endl;
    }
};

class UPIPayment : public PaymentStrategy
{
public:
    void pay(const string& amount)
    {
        cout <<amount<<" "<<"paid successfully by UPI"<<endl;
    }
};

class PaymentProcessor
{
    string amount;
    PaymentStrategy *strategy;

public:
    PaymentProcessor(const string& a, PaymentStrategy *cpay) : amount(a), strategy(cpay) {}

    void ProcessPayment()
    {
        strategy->pay(amount);
    }

    void setStrategy(PaymentStrategy* newstrategy){
        this->strategy = newstrategy;
    }
};

int main()
{
    init_code();
    string amount1,amount2,amount3;
    cin >> amount1>>amount2>>amount3;

    CreditCardPayment cpay;
    DebitCardPayment dpay;
    UPIPayment upay;

    PaymentProcessor processor1(amount1, &cpay);
    processor1.ProcessPayment();


    PaymentProcessor processor2(amount2,&dpay);
    PaymentProcessor processor3(amount3,&upay);

    processor2.ProcessPayment();
    processor3.ProcessPayment();

    processor3.setStrategy(&cpay);

    processor3.ProcessPayment();
    
}