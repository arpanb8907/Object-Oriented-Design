// 📄 Problem Statement:
// Design a Notification System that supports sending alerts to users via:

// 📩 Email

// 📱 SMS

// 🔔 Push Notification

// 🎯 Requirements:
// The system should be able to send a message using any or multiple notification methods.

// You should be able to add new notification channels (e.g., WhatsApp, Slack) without modifying existing code.

// Use good object-oriented design practices and follow SOLID principles.

// The system should be extensible, testable, and follow separation of concerns.

// Use appropriate design patterns (hint: Strategy, maybe Composite if multiple senders).



#include<bits/stdc++.h>
using namespace std;
void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

class notificationsChannel{
public:
    virtual void triggered() const =0;
    virtual string type() const =0;
};


class SMSChannel: public notificationsChannel{
public:

    void triggered() const override{
        cout<<"SMS has been triggered"<<endl;
    }

    string type() const override{
        return "SMS";
    }
    

};

class EmailChannel: public notificationsChannel{
public:

    void triggered() const override{
        cout<<"Email has been triggered"<<endl;
    }
    string type() const override{
        return "Email";
    }

};

class Push_notifications{
    vector<notificationsChannel*> channels;
public:
    Push_notifications(vector<notificationsChannel*> ch) : channels(ch){}
    void notify(){

        for(auto type: channels){
            type->triggered();
        }
    }
};

int main(){
    //init_code();

    vector<notificationsChannel*>v;
    EmailChannel* e = new EmailChannel();
    SMSChannel *s = new SMSChannel() ;
    SMSChannel *s1 = new SMSChannel();
    EmailChannel *e1 = new EmailChannel();
    v.push_back(e);
    v.push_back(s);
    v.push_back(e1);
    v.push_back(s1);

    Push_notifications p(v);

    p.notify();
    


}