#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


class Logger{
    static int counter;
    static Logger* loggerInstance;

    Logger(){
        counter++;
        cout<<"Logger instance is created , No of instances :"<<counter<<endl;
    }
public:
    
    static Logger* getLogger(){
        if(loggerInstance==nullptr){
            loggerInstance = new Logger();
        }

        return loggerInstance;
    }

    void log(string msg){
        cout<<msg<<endl;
    }

};

int Logger :: counter = 0;
Logger* Logger :: loggerInstance = nullptr;




int main(){
    //init_code();

    Logger *logger1 = Logger::getLogger();
    Logger *logger2 = Logger::getLogger();
    Logger *logger3 = Logger::getLogger();  

    logger1->log("Logs from user1");
    logger2->log("Logs from user2");
    logger3->log("Logs from user3");


}