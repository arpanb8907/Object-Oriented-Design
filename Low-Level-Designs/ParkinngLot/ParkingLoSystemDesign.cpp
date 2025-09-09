#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include<atomic>
#include<thread>
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
	virtual string get_Type() = 0;
	virtual ~Vehicle() {}
};

class Bike : public Vehicle
{
public:
	void createVehicle()
	{
		cout << "Bike is created" << endl;
	}
	string get_Type()
	{
		return "Bike";
	}
};

class Car : public Vehicle
{
public:
	void createVehicle()
	{
		cout << "Car is created" << endl;
	}
	string get_Type()
	{
		return "Car";
	}
};

class Bus : public Vehicle
{
public:
	void createVehicle()
	{
		cout << "Bus is created" << endl;
	}

	string get_Type()
	{
		return "Bus";
	}
};

class VehicleFactory
{
public:
	static Vehicle *generateVehicle(const string &vehicleType)
	{

		if (vehicleType == "Car")
		{
			return new Car();
		}

		else if (vehicleType == "Bike")
		{
			return new Bike();
		}

		else if (vehicleType == "Bus")
		{
			return new Bus();
		}
	}
};

class ENUM
{
	vector<string> status = {"Failed", "Success", "Pending"};

public:
	string get_status(int ind)
	{
		return status[ind];
	}
};

class PaymentStrategy
{
public:
	virtual bool PaymentDone(string& amount) = 0;

	virtual ~PaymentStrategy() {}
};

class DebitCardPayment : public PaymentStrategy
{
public:
	bool PaymentDone(string &amount)
	{
		cout << "Payment of Rs" << " " << amount << " " << "done by Debit Card" << endl;
		return true;
	}
};

class CreditCardPayment : public PaymentStrategy
{
public:
	bool PaymentDone(string &amount)
	{
		cout << "Payment of Rs" << " " << amount << " " << "done by Credit Card" << endl;
		return true;
	}
};

class UPIPayment : public PaymentStrategy
{
public:
	bool PaymentDone(string &amount)
	{
		cout << "Payment of Rs" << " " << amount << " " << "done by UPI" << endl;
		return true;
	}
};

class ProcessPayment
{
public:
	string process(PaymentStrategy *strategy,float& cost)
	{
		ENUM e;
		string amount = to_string(cost);
		if (strategy->PaymentDone(amount))
		{

			return e.get_status(1);
			
		}

		else
		{
			return e.get_status(1);
		}
	}
};
class Ticket
{
	Vehicle &vehicle;
	string entryTime;
	string SpotId;
	string UserId;
public:
	Ticket(Vehicle &vehicle, string entryTime,const string& Id,const string& userId) : vehicle(vehicle), entryTime(entryTime) , SpotId(Id), UserId(userId) {}

	string get_entryTime()
	{
		return entryTime;
	}

	string get_vehicle_details()
	{
		return vehicle.get_Type();
	}

	string spot_Id(){
		return SpotId;
	}

	string get_userId(){
		return UserId;
	}
};

class ParkingSpot
{
	bool isOccupied;
	string vehicleType;
	string id;

public:
	ParkingSpot() : isOccupied(false), id(""), vehicleType("") {} 
	
	ParkingSpot(string id, string vehicleType)
		: isOccupied(false), id(id), vehicleType(vehicleType) {}

	string spotType()
	{
		return vehicleType;
	}
	string getId()
	{
		return id;
	}
	bool isavailable()
	{	
		if(isOccupied) return false; 
		return true;
	}

	void toggelStatus()
	{
		isOccupied = !isOccupied;
	}
};
class ParkingFloor
{
	unordered_map<string, ParkingSpot> spots;

public:
	void add_spot(string &id, const ParkingSpot &spot)
	{
		spots.insert({id, spot});
	}

	void viewSpots(){

		for(auto i:spots){
			cout<<i.first<<" "<<i.second.isavailable()<<endl;
		}
		cout<<endl;
	}
	void remove_spot(Ticket* ticket){
		
		viewSpots();

		string spotId = ticket->spot_Id();
		spots[spotId].toggelStatus();

		viewSpots();
		

	}

	
	ParkingSpot *find_avl_spots(const string &vehicleType)
	{
		for (auto &i : spots)
		{	
			
			if (i.second.isavailable() && i.second.spotType() == vehicleType)
			{
				i.second.toggelStatus();
				return &i.second;
			}
		}
		return nullptr;
	}
};
class ParkingLot
{
	unordered_map<string, ParkingFloor> floors;
	unordered_map<string, Ticket *> ActiveTickets;
	
	static ParkingLot* PInstance;
	ParkingLot(){
		cout<<"ParkingLot instance created"<<endl;
	}
public:
	static ParkingLot* getInstance(){
		if(PInstance == nullptr){
			PInstance = new ParkingLot();
		}

		return PInstance;
	}

	void add_floor(string &id, const ParkingFloor &floor)
	{
		floors[id] = floor;
	}

	Ticket *park(Vehicle *vehicle, string &entryTime, string &id)
	{

		ParkingSpot *spot = nullptr;
		for (auto &i : floors)
		{

			spot = i.second.find_avl_spots(vehicle->get_Type());

			if (spot)
				break;
		}

		if (spot)
		{
			cout << "Spot found with id:" << " " << spot->getId() << endl;
			cout << "Parked" << endl;
			spot->toggelStatus();

			Ticket *ticket = new Ticket(*vehicle, entryTime,spot->getId(),id);
			ActiveTickets[id] = ticket;
			return ticket;
		}

		else
		{
			cout << "No spot left for " << vehicle->get_Type() << endl;
		}

		return nullptr;
	}

	void unpark(Ticket *ticket,const string& fid)
	{
		

		// find floor 
		
		for(auto  &floor: floors){
			if(floor.first==fid){
				floor.second.remove_spot(ticket);
                break;
			}
		}

		

		// Demolish ticket

		ActiveTickets.erase(ticket->get_userId());
		
		cout << "Unparked"<<" "<< ticket->get_vehicle_details()<<" "<<"with spot Id"<<" "<<ticket->spot_Id()<<endl;

	}



	void getActiveticketDetails()
	{
		for (auto tkt : ActiveTickets)
		{
			cout << "Ticket id -> " << tkt.first << " " << "with " << "following details :" << " " << "Vehicle Details : " << tkt.second->get_vehicle_details() << " and" << " " << "entyTime is : " << tkt.second->get_entryTime() << endl;
		}
		cout<<endl;
	}
};

class Gate
{
public:
	virtual Ticket* executeTask(ParkingLot& Pl,string& entryTime,string& userId,string&type) = 0;

	virtual ~Gate() {}
};

class EntryGate : public Gate
{

public:
	Ticket* executeTask(ParkingLot& Pl,string& entryTime,string& userId,string& type) override
	{
		// generate ticket with metadata;
		
		Vehicle *bike = VehicleFactory ::generateVehicle(type);
		Ticket *ticket = Pl.park(bike, entryTime, userId);

		return ticket;
	}
};

class ExitGate : public Gate
{
public:
	Ticket* executeTask(ParkingLot& Pl,string& entryTime,string& userId,string& type) override
	{
		return nullptr;

		
	}

	void executeTaskWithTKT(ParkingLot& Pl,Ticket* ticket,const string& fid){
		// release the spot 
		// take the payment

		UPIPayment *UPI = new UPIPayment();
		ProcessPayment* payment = new ProcessPayment();

		string exitTime = "11:24";
		string entryTime = ticket->get_entryTime();
	
		int min1 = stoi(exitTime.substr(3,2)) , min2 = stoi(entryTime.substr(3,2));
		int d_min = 0,d_hr = 0;
		if(min1>min2){
			d_min = min1-min2;
		}

		else{
			d_min = 60+min1-min2;
		}

		string h= "";
		int i=0;
		while(i<exitTime.length() && exitTime[i]!=':'){
			h+=exitTime[i];
			i++;
		}

		i=0;
		string h1="";

		while(i<entryTime.length() && entryTime[i]!=':'){
			h1+=entryTime[i];
			i++;
		}
		

        
		int hr1 = stoi(h) , hr2 = stoi(h1);
        
		if(hr1>hr2){
			d_hr = hr1-hr2;
		}

		else{
			d_hr = 24+hr1-hr2;
		}

       
		d_min = d_hr*60 + d_min;
		
		float cost = d_min/3.0;

		if(payment->process(UPI,cost)=="Success"){
			// release the spot 
			// demolish the ticket 

			Pl.unpark(ticket,fid);

			
		}

		return;
	}
};

ParkingLot* ParkingLot :: PInstance = nullptr;





int main()
{
	init_code();

	ParkingLot *Pl = ParkingLot :: getInstance();
	ParkingFloor floor1;
	string id1 = "FL1";
	string sid1 = "SP1BIKE", sid2 = "SP2CAR", sid3 = "SP3BUS", sid4 = "SP4CAR";

	ParkingSpot spot1(sid1, "Bike");
	ParkingSpot spot2(sid2, "Car");
	ParkingSpot spot3(sid3, "Bus");
	ParkingSpot spot4(sid4, "Car");

	floor1.add_spot(sid1, spot1);
	floor1.add_spot(sid2, spot2);
	floor1.add_spot(sid3, spot3);
	floor1.add_spot(sid4, spot4);

	Pl->add_floor(id1, floor1);

	

	// user arrives	
	string entryTime1 = "8:00";
	string userID1 = "user1";
	string type1 = "Bike";

	string entryTime2 = "8:00";
	string userID2 = "user2";
	string type2 = "Car";

	// at the Entry Gate
	EntryGate * Entry = new EntryGate();
	EntryGate* Entry1 = new EntryGate();

	// Ticket issued if spot present
	Ticket* ticket1 =  Entry->executeTask(*Pl,entryTime1,userID1,type1);
	
	
	

	if(ticket1){
		cout<<"ticket details are :"<<" "<<ticket1->spot_Id()<<" "<<ticket1->get_vehicle_details()<<" "<<ticket1->get_entryTime()<<endl;


		
	}
	
	ExitGate* Exit = new ExitGate();
	Exit->executeTaskWithTKT(*Pl,ticket1,userID1);
	
	Ticket* ticket2 = Entry1->executeTask(*Pl,entryTime2,userID2,type2);

	if(ticket2){
		cout<<"ticket details are :"<<" "<<ticket2->spot_Id()<<" "<<ticket2->get_vehicle_details()<<" "<<ticket2->get_entryTime()<<endl;

		
		cout<<"Current active tickets are :"<<endl;
	}

	
	
	cout<<"Current active tickets are :"<<endl;
	Pl->getActiveticketDetails();


	
}