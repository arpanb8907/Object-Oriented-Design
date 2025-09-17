#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}



class SQLRepository{
public:
    void get(string id){
        cout<<"User is fetched from SQL DB"<<endl;
    }
};


class MongoDbRepository{
public:
    void find(string id){
        cout<<"User is fetched from Mongo DB"<<endl;
    }
};


class UserService{
    SQLRepository* repository = new SQLRepository();
public:
    void get(string id){
        repository->get(id);
    }
};

int main(){
    init_code();
    
    UserService us;
    us.get("001");

}