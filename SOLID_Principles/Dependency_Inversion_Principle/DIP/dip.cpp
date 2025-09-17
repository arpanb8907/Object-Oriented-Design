#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class IRepository{
public:
    virtual void get(string id) = 0;
    virtual ~IRepository(){}
};

class SQLRepository : public IRepository{
public:
    void get(string id){
        cout<<"User is fetched from SQL DB"<<endl;
    }
};


class MongoDbRepository : public IRepository{
public:
    void get(string id){
        cout<<"User is fetched from Mongo DB"<<endl;
    }
};


class UserService{
    IRepository* repository;
public:
    UserService(IRepository* repo){
        repository = repo;
    }
    void get(string id){
        repository->get(id);
    }

    void setRepositoy(IRepository* repo){
        repository = repo;
    }
};

int main(){
    init_code();
    
    SQLRepository* repo = new SQLRepository;
    UserService* us = new UserService(repo);
    string id = "abhowmick1312";

    us->get(id);
    us->setRepositoy(new MongoDbRepository());
    us->get(id);
    

}