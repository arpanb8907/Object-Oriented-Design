#include<bits/stdc++.h>
using namespace std;
void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class DBConnection{
public:
    DBConnection(){
        cout<<"instance is created"<<endl;
    }
    void getDBConnection(string client){
        cout<<client<<" "<<"is connected to database"<<endl;
    }
};

int main(){
    init_code();

    DBConnection db;

    db.getDBConnection("Arpan");
    db.getDBConnection("Bhowmick");
}