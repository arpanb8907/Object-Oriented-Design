#include<bits/stdc++.h>
using namespace std;


class user{

    string u_id;
    string username;
public:
    user(){
        u_id = "";
        username = "";   
    }

    void update_user(string name,string id){
        username = name;
        u_id = id;

    }

    pair<string,string> get_user_details(){

        if(u_id=="" || username=="") return {"No user","No id"};

        return {username,u_id};
    }

    bool validate_user(string name , string id){

        if(name!=username || id!=u_id) return false;

        return true;
    }
};


class student : public user{
    
public:
    
    void role(){
        cout<<"User is a student";
    }
    
};

class admin : public user{
    
public:
    
    void role(){
        cout<<"User is a admin";
    }
    
};


int main(){

   
   student s1;
   
   s1.role();
    
    
    
    
    
}
