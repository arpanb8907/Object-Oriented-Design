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

int main(){

    user *user1 = new user();
    string name ,uid;
    cin>>name>>uid;
    user1->update_user(name,uid);

    cout<<user1->get_user_details().first<<" "<<user1->get_user_details().second;
}
