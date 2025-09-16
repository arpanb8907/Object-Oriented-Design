#include<bits/stdc++.h>
#include<functional>
using namespace std;
void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}


class user{
    vector<pair<string,string>>database;
    string username;
public:
    user(string uname): username(uname){}
    
    void saveToDB(string uname1, string hashedpwd){
        database.push_back({uname1,hashedpwd});

        cout<<"Data of"<<" "<<uname1<<" "<<"saved into database"<<endl;
    }

    void sendEmail(){
        cout<<"Email is sent the user"<<endl;
    }

    string GethashPasword(string password){
        hash<string>hashcode;

        return to_string(hashcode(password));

    }

    void log(string msg){
        cout<<msg<<endl;
    }

    string getUsername(){
        return username;
    }
};


int main(){
    init_code();
    user* user1 = new user("abhowmick");
    string hashpwd = user1->GethashPasword("Hey123@");
    user1->saveToDB(user1->getUsername(),hashpwd);
    user1->sendEmail();

    user1->log("Hi this is "+user1->getUsername());

}