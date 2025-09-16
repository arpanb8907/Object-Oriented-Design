#include <bits/stdc++.h>
#include <functional>
using namespace std;
void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class user
{
    string username;
    string email;
    string password;
public:
    user(string uname ,string email,string password) : username(uname) , email(email), password(password) {}

    string getUsername()
    {
        return username;
    }
    string getEmail(){
        return email;
    }

    
};

class UserRepository
{
    vector<user*> database;

public:
    void saveToDB(user* user)
    {
        database.push_back(user);

        cout << "Data of" << " " << user->getUsername() << " " << "saved into database" << endl;
    }
};

class LoggerService
{
public:
    void log(string msg)
    {
        cout << msg << endl;
    }
};

class EmailService
{
public:
    void sendEmail(string email)
    {
        cout << "Email is sent to "<<email<< endl;
    }
};

class UserService{
    UserRepository *repository = new UserRepository();
    EmailService* emailservice = new EmailService();
    LoggerService* loggerservice = new LoggerService();

public:
    void registerUser(string name,string email,string password){
        hash<string>hasher;
        string hashedpwd = to_string(hasher(password));
        user *user1 = new user(name,email,hashedpwd);

        repository->saveToDB(user1);
        emailservice->sendEmail(email);
        loggerservice->log(name + "is registered successfully");


    }
};

int main()
{
    
    init_code();
    
    UserService app;
    app.registerUser("Arpan Bhowmick","abhowmick@gmail.com","Hey123@");

}