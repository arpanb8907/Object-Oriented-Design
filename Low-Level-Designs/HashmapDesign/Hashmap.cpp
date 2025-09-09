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

class Hashmap
{
    vector<list<pair<string, string>>> arr;
    float lf; // Load Factor
    int non;

public:
    Hashmap()
    {
        arr.resize(4);
        lf = 0.75;
        non = 0;
    }

    // Time Complexity : O(1) 
    size_t getHashcode(string s)
    {
        hash<string> hashcode;
        int capacity = arr.size();

        return (hashcode(s));
    }


    // Time Complexity : O(1) Amortized
    void put(string key, string value)
    {
        int capacity = arr.size();

        if (non > (lf * capacity))
        {
            Rehash();
        }

        hash<string> hashcode;
        size_t hashvalue = getHashcode(key);
        hashvalue %= capacity;

        for (auto &it : arr[hashvalue])
        {
            if (it.first == key)
            {
                it.second = value;
                return;
            }
        }
        arr[hashvalue].push_back({key, value});

        non++;
    }

    // Time Complexity : O(1) Amortized
    string get(string key)
    {

        int capacity = arr.size();
        size_t hashvalue = getHashcode(key);
        hashvalue %= capacity;

        if (arr[hashvalue].size() == 0)
            return (key + " " + "not found");

        for (auto &it : arr[hashvalue])
        {
            if (it.first == key)
            {

                return it.second;
            }
        }

        return (key + " " + "not found");
    }

    // Time Complexity : O(1) Amortized
    void remove(string key)
    {
        int capacity = arr.size();

        size_t hashvalue = getHashcode(key);
        hashvalue %= capacity;
        for (auto it = arr[hashvalue].begin(); it != arr[hashvalue].end();)
        {

            if (it->first == key)
            {
                non--;
                it = arr[hashvalue].erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    // Time Complexity : O(N)
    void Rehash()
    {
        int currsize = arr.size();

        vector<list<pair<string, string>>> tmp(currsize * 2);
        int capacity = currsize * 2;

        for (auto &bucket : arr)
        {

            for (auto &it : bucket)
            {
                hash<string> hashcode;
                size_t hashvalue = getHashcode(it.first);
                hashvalue %= capacity;
                tmp[hashvalue].push_back({it.first, it.second});
            }
        }
        arr.resize(currsize * 2);
        arr = tmp;
    }

    int getSize()
    {
        return arr.size();
    }
};

int main()
{
    init_code();

    Hashmap *map = new Hashmap();

    map->put("Alice", "This is Alice's place");
    map->put("Bob", "This is Bob's place");
    map->put("Tom", "This is Tom's place");
    map->put("Arpan", "This is Arpan's place");
    map->put("Daniel", "This is Daniel's place");
    map->put("Arjun", "This is Arjun's place");
    map->put("Jitesh", "This is Jitesh's place");
    map->put("Shashi", "This is Shashi's place");
    map->put("Arpan", "Arpan Bhowmick is arriving...");

    cout << map->get("Alice") << endl;
    cout << map->get("Arpan") << endl;
    cout << map->get("Jitesh") << endl;

    map->remove("Jitesh");

    cout << map->get("Jitesh") << endl;
}