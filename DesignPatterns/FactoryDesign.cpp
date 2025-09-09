#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class Vehicle
{
public:
    virtual void createVehicle() = 0;
};

class car : public Vehicle
{
public:
    void createVehicle()
    {
        cout << "Car is created" << endl;
    }
};

class bike : public Vehicle
{
public:
    void createVehicle()
    {
        cout << "Bike is created" << endl;
    }
};

class bus : public Vehicle
{
public:
    void createVehicle()
    {
        cout << "Bus is created" << endl;
    }
};

class VehicleFactory
{

public:
    static Vehicle *generateVehicle(const string &vehicleType)
    {
        if (vehicleType == "car")
        {
            return new car();
        }

        else if (vehicleType == "bike")
        {
            return new bike();
        }

        else if (vehicleType == "bus")
        {
            return new bus();
        }

        else{
            return nullptr;
        }
    }
};

int main()
{
    //init_code();

    string vehicleType;
    cin >> vehicleType;
    for (char &ch : vehicleType) ch = tolower(ch);
    Vehicle *vehicle = VehicleFactory ::generateVehicle(vehicleType);

    if(vehicle){
        vehicle->createVehicle();
    }

    else{
        cout<<"Invalid vehicle type"<<endl;
    }

    
}