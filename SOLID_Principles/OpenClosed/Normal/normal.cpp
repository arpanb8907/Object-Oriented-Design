#include<bits/stdc++.h>
using namespace std;

class PaymentMethod{
public:
    enum class Type{
        CreditCard,
        DebitCard,
        UPI
    };
};


class Payment{
public:
    void pay(PaymentMethod::Type method){

        if(method==PaymentMethod::Type::CreditCard){
            cout<<"payment is done by CreditCard"<<endl;
        }

        else if(method==PaymentMethod::Type::DebitCard){
            cout<<"payment is done by DebitCard"<<endl;
        }

        else if(method==PaymentMethod::Type::UPI){
            cout<<"payment is done by UPI"<<endl;
        }

        else{
            cout<<"Invalid payment method";
        }

        
    }
};


int main(){
    Payment payment;
    payment.pay(PaymentMethod::Type::CreditCard);
}