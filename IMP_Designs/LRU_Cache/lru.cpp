#include<bits/stdc++.h>
using namespace std;

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

class Book{
    int bookId;
    string bookData;
public:
    Book(int id,string data) : bookId(id) , bookData(data){}

    int getId(){
        return bookId;
    }
    string getData(){
        return bookData;
    }
};

class CacheStrategy{
public:
    virtual void put(int id,Book* book) = 0;
    virtual Book* get(int id) = 0;
    virtual ~CacheStrategy(){}
};

class LRUCache: public CacheStrategy{
private:
    int capacity;
    list<pair<int,Book*>>order;
    unordered_map<int,list<pair<int,Book*>>::iterator>CacheMap;
public:
    LRUCache(int k) : capacity(k){}

    void put(int id,Book* book){
        // if id already exist

        if(CacheMap.find(id)!=CacheMap.end()){

            CacheMap[id]->second = book;
            order.splice(order.begin(),order,CacheMap[id]);
            return;
        }

        if(order.size()==capacity){
            int lru_Id = order.back().first;
            order.pop_back();
            CacheMap.erase(lru_Id);
        }

        // add new data in cache 
        order.push_front({id,book});
        CacheMap[id] = order.begin();

    }

    Book* get(int id){
        // if book is bot in the cache return -1;
        if(CacheMap.find(id)==CacheMap.end()) return nullptr;

        auto it = CacheMap[id];
        order.splice(order.begin(),order,it);

        return it->second;
    }
};


class CacheManagement{
    CacheStrategy * strategy;
public:
    void setStrategy(CacheStrategy* Currstrategy){
        strategy = Currstrategy;
    }

    void execute_put(int id,Book* book){

        if(strategy){
            strategy->put(id,book);
            
        }

        else{
            cout<<"Starategy is not defined yet"<<endl;
        }
    } 

    void execute_get(int id){
        if(strategy){
            Book* book = strategy->get(id);
            if(!book) cout<<"Book not found in the cache"<<endl;

            else{
                cout<<book->getData()<<endl;
            }
            
        }

        else{
            cout<<"Starategy is not defined yet"<<endl;
        }
    }
    
};

int main(){
    init_code();

    int k=4;
   

    CacheManagement cm;
    
    Book book1(101,"Zero to One");
    Book book2(102,"GATE");
    Book book3(103,"Git");
    Book book4(104,"Artificial Intelligence");
    Book book5(105,"Kth largest");
    Book book6(106,"Final Destination");
    Book book7(107,"Black Book");
    Book book12(102,"Book 102");
    
    LRUCache lru(k);
    cm.setStrategy(&lru);
    
    cm.execute_put(101,&book1);
    cm.execute_put(102,&book2);
    cm.execute_put(106,&book6);
    cm.execute_put(104,&book4);
    
    cm.execute_get(102);
    cm.execute_put(101,&book12);  
    
    cm.execute_get(101);
    cm.execute_get(104);
}