#include<bits/stdc++.h>
using namespace std;

// If a class only uses another class in parameters, return types, or local variables → Dependency.
// If a class owns multiple instances of another class and their life cycle is tied → Composite relationship.


// Hence Document ---> Memento (Dependancy relationship)
// Memento -----> CareTaker(Composition Relationship)


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

class Memento{
    string memento;
public:
    Memento(string doc): memento(doc){}

    string getSavedMemento(){
        return memento;
    }
};

class Document{
    string content;
public:
    void setDocument(string document){
        if(content.length() >0) {
            content+= '\n';
        }

        content += document;
    }

    void getContent(){
        cout<<content<<endl;
    }

    Memento createMemento(){
        return Memento(content);
    }

    void restoreMemento(Memento memento){
        content = memento.getSavedMemento();
    }
};

class CareTaker{
    vector<Memento>Snapshots;
public:
    CareTaker(): Snapshots(){}

    void addMemento(Memento memento){
        Snapshots.push_back(memento);
    }

    Memento GetMemento(int index){
        if(index>= 0 && index<Snapshots.size()){
            return Snapshots[index];
        }
        throw  std:: out_of_range("invalid Memento Index");
       
    }  
};


int main(){
    //init_code();

    Document document;
    CareTaker Snapshots;

    document.setDocument("State 0 : Designing system");
    Snapshots.addMemento(document.createMemento());

    document.setDocument("State 1 : Scaling up the sytem");
    Snapshots.addMemento(document.createMemento());

    document.setDocument("State 2 : Hosting backend i  AWS EC2");
    Snapshots.addMemento(document.createMemento());

    document.setDocument("State 3 : Ready...");
    Snapshots.addMemento(document.createMemento());

   
    document.restoreMemento(Snapshots.GetMemento(1));

    
    document.getContent();

    cout<<"restoration test done ... till 1"<<endl;

    document.restoreMemento(Snapshots.GetMemento(3));

    document.getContent();
    cout<<"restoration test done ...till 3"<<endl;

    document.restoreMemento(Snapshots.GetMemento(2));
    

    document.getContent();
    cout<<"restoration test done ...till 2"<<endl;

}