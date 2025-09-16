#include <bits/stdc++.h>

using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

class Obstacle
{
public:
    virtual void createObstacle() = 0;
    virtual int destination() = 0;
};

class Snakes : public Obstacle
{
    int src, dest;

public:
    Snakes(int &source, int &destination) : src(source), dest(destination) {}

    void createObstacle()
    {
        cout << "Snakes is created" << endl;
    }
    int destination()
    {
        return dest;
    }
};

class Ladder : public Obstacle
{
    int dest, src;

public:
    Ladder(int &source, int &destination) : src(source), dest(destination) {}

    void createObstacle()
    {
        cout << "Ladder is created" << endl;
    }

    int destination()
    {
        return dest;
    }
};

class ObstacleFactory
{
public:
    static Obstacle *generateObstacle(string &obstacleType, int &source, int &destination)
    {

        if (obstacleType == "snakes")
        {
            Snakes *snakes = new Snakes(source, destination);
            return snakes;
        }

        if (obstacleType == "ladder")
        {
            Ladder *ladder = new Ladder(source, destination);
            return ladder;
        }

        return nullptr;
    }
};

class Icell
{

public:
    virtual int getNumber() = 0;
    virtual bool hasObstacle() = 0;
    virtual void addObstacle(Obstacle *obstacle) = 0;
    virtual Obstacle *getObstacle() = 0;
    virtual bool iswin(int pos) = 0;
};

class cell : public Icell
{
    int num;
    bool hasobstacle;
    Obstacle *obs;

public:
    cell(int n, bool obs) : num(n), hasobstacle(obs) {}

    int getNumber()
    {
        return num;
    }
    bool hasObstacle()
    {
        return hasobstacle;
    }
    void addObstacle(Obstacle *obstacle)
    {
        obs = obstacle;
        hasobstacle = true;
    }

    Obstacle *getObstacle()
    {
        return obs;
    }

    bool iswin(int pos){

    }
};

class Iboard
{
public:
    virtual void setBoard(int row, int col) = 0;
    virtual void setObstacles(int source, int dest, string type) = 0;
};

class Iuser
{
public:
    virtual void setUserId(string &id) = 0;
    virtual string getUserId() = 0;
    virtual void setPosition(int r,int c)=0;
};

class user : public Iuser
{
    string userId;
    int position;

public:
    user() : position(0) {}

    void setUserId(string &id)
    {
        userId = id;
    }

    string getUserId()
    {
        return userId;
    }

    int getPosition()
    {
        return position;
    }

    void setPosition(int row,int col){
        // check win or not 

        

    }
};

class board : public Iboard
{
    vector<vector<cell *>> grid;

public:
    void setBoard(int row, int col)
    {
        grid.resize(row, vector<cell *>(col, nullptr));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int number = (i + 1) * (j + 1);
                cell *c = new cell(number, false);
                if(i%2){
                    grid[i][col-j-1] = c;
                }
                else{
                    grid[i][j] = c;
                }
                
            }
        }
    }

    void setObstacles(int source, int destination, string type)
    {

        int row1 = (source-1) / 8, col1 = (source-1) % 8, row2 = (source-1) / 8, col2 = (source-1) % 8;

        Obstacle *obstacle = ObstacleFactory ::generateObstacle(type, source, destination);

        grid[row1 ][col1 ]->addObstacle(obstacle);
        grid[row2 ][col2 ]->addObstacle(obstacle);
    }
};

class IDice{
public:
    virtual int roleDice()=0;
};

class SingleDice:public IDice{
public:
    int roleDice(){
        srand(time(0));

        return (rand()%6)+1 ;
    }
};
class Game
{
public:
    void setGame()
    {
        board *Board = new board();
        int boardsize = 64,r = sqrt(boardsize),c = r;
        Board->setBoard(8, 8);
        int source1 = 22, dest1 = 63;
        string type1 = "ladder";

        int source2 = 7, dest2 = 36;
        string type2 = "ladder";

        int source3 = 61, dest3 = 3;
        string type3 = "snakes";

        int source4 = 35, dest4 = 21;
        string type4 = "snakes";

        int source5 = 19, dest5 = 51;
        string type5 = "Ladder";

        Board->setObstacles(source1, dest1, type1);
        Board->setObstacles(source2, dest2, type2);
        Board->setObstacles(source3, dest3, type3);
        Board->setObstacles(source4, dest4, type4);
        Board->setObstacles(source5, dest5, type5);
    }

    void startGame()
    {
        SingleDice* dice1 = new SingleDice();
        int t=10;
        user* user1 = new user();

        while(t--){
            int curr = dice1->roleDice();
            int row = (curr-1)%8 , col = (curr-1)/8;
            user1->setPosition(row,col);
        }
    }
};

int main()
{

    init_code();

    
}