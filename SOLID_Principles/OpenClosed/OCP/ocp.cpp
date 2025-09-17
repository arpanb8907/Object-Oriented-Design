#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class IPayment{
public:
    virtual void pay()=0;
};

class CreditCardPayment: public IPayment{
public:
    void pay(){
        cout<<"Payment is done by CreditCard"<<endl;
    }
};

class DebitCardPayment: public IPayment{
public:
    void pay(){
        cout<<"Payment is done by DebitCard"<<endl;
    }
};

class UPIPayment: public IPayment{
public:
    void pay(){
        cout<<"Payment is done by UPI"<<endl;
    }
};


class PaymentServie{
public:
    void pay(IPayment* method){
        method->pay();
    }
};

int main(){
    init_code();
    
    PaymentServie ps;
    DebitCardPayment* method1 = new DebitCardPayment();

    ps.pay(method1);

}