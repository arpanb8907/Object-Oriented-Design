#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class IUser
{
public:
    virtual void notify() = 0;
};

class User : public IUser
{
    int uid;
    string name;

public:
    User(int id, string name) : uid(id), name(name) {}

    void notify()
    {
        cout << "User with userId " << uid << " " << "and name " << name << " " << "is notified" << endl;
    }
};

class Group
{
    vector<IUser *> arr;

public:
    void subscribe(IUser &user)
    {
        arr.push_back(&user);
    }

    void Unsubscribe(IUser &user)
    {
        auto it = find(arr.begin(), arr.end(), &user);

        arr.erase(it);
    }
    void notify()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i]->notify();
        }
    }
};
int main()
{
    //init_code();

    Group group;

    User user1(1, "Arpan");
    User user2(2, "Reesha");
    User user3(3, "Kahuri");

    group.subscribe(user1);
    group.subscribe(user2);
    group.subscribe(user3);

    group.notify();
    group.Unsubscribe(user1);

    group.notify();
}