// ✅ Q1. Online Movie Ticket Booking
// 📄 Design a system like BookMyShow that handles:

// Movies, Showtimes, Seats

// Users booking tickets

// Applying different discount strategies (seasonal, festival, student)

// 🎯 Hint: Think of separation of responsibilities, strategy for discount, and class extension for new movie types.

#include<bits/stdc++.h>
using namespace std;
void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}


class Movies{
    string id,name;
public:
    
    void set_id(string movie_id){
        id = movie_id;
    }
    void set_name(string movie_name){
        name = movie_name;
    }

    string get_id(){
        return id;
    }
    string get_name(){
        return name;
    }

};

class ShowTimes{
    vector<string> timings;
public:

    void add_timings(string time){
        timings.push_back(time);
    }

    vector<string> get_timings(){
        return timings;
    }

};

class Seats{
    map<string,int>seats_data;
public:
    

    void add_seats(){
        for(int i=0;i<10;i++){
            seats_data[to_string(i)]=0;
        }
    }
    map<string,int> get_seat_details(){
        return seats_data;
    }

};

class User{
    string userId,username;
public:
    void set_userId(string id){
        userId = id;
    }
    void set_username(string uname){
        username = uname;
    }

};

class Discount{
public:
    virtual double calculate(double mrp) const=0; 
};

class seasonalDiscount : public Discount{
public:
    double calculate(double mrp) const override{
        return (0.95*mrp);
    }
};

class festivalDiscount : public Discount{
public:
    double calculate(double mrp) const override{
        return (0.85*mrp);
    }
};

class studentDiscount : public Discount{
public:
    double calculate(double mrp) const override{
        return (0.88*mrp);
    }
};

class Booking{
    User user;
    Movies movie;
    //map<string,int>timings;
    string time;
    Discount * discount;
public:
    Booking(User u,Movies m,string t ,Discount* d1): user(u),movie(m), discount(d1) , time(t){}
    
    void Initiate_booking(){
        double price = discount->calculate(286.00);
        cout<<"Booking Done✅ with "<<price<<" "<<"rupees"<<endl;
    }
};
int main(){

    //init_code();

    User u;
    Movies m;
    ShowTimes t;
    Seats s;

    u.set_userId("1");
    u.set_username("Arpan Bhowmick");

    m.set_id("X002");
    m.set_name("Narsimha Avtar");
    seasonalDiscount sd;
    
    Booking b(u,m,"20:30",&sd);

    b.Initiate_booking();
    
}