#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}



class User{
    string userID,userName;
    vector<IFile*>Files;
public:

    string GetUserID(){
        return userID;
    }
    string getUsername(){
        return userName;
    }
};


class IFile{
    string type;
    string owner;
public:
    virtual string GetType() = 0;
    virtual string SetType() = 0;

    virtual ~IFile(){}
};

class PdfFile{
    string type;
    string owner;
public:
    string GetType(){
        return type;
    }

    string SetType(){
        type = "PDF";
    }
};

class JpegFile{
    string type;
    string owner;
public:
    string GetType(){
        return type;
    }

    string SetType(){
        type = "JPEG";
    }
};


class FileService{
    unordered_map<string,IFile*> fileDB;

public:
    void create(){

    }

    void update(){

    }

    void remove(){

    }
};

class AuthenticationService{
    unordered_map<string,User*>userDB;
    
public:
    void login(){

    }
    void logout(){

    }
};

int main(){
    init_code();

    cout<<"Designing googleDrive...."<<endl;
}