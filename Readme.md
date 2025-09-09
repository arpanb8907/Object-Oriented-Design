--- 

To run cpp file --->

g++ -std=c++17 -g MementoDesign.cpp -o MementoDesign.exe
.\MementoDesign.exe

| Pattern   | When & Why                           | Steps (Flow)                          
|-----------|--------------------------------------|----------------------------------------|
| Observer  | Notify many on one state change      | 1. Subject keeps observers             |
|           | (pub-sub).                           | 2. Observer interface (update)         |
|           |                                      | 3. Observers implement interface       |
|           |                                      | 4. Subject notifies all observers 
     
| Factory   | Create objs w/o exposing logic       | 1. Define factory method              
|           | (loose coupling).                    | 2. Concrete classes implement interface|
|           |                                      | 3. Factory chooses instance            |
|           |                                      | 4. Client calls factory, not `new` 
    
| Singleton | Only one instance needed (e.g. log). | 1. Private constructor                 |
|           |                                      | 2. Static reference inside class       |
|           |                                      | 3. Static getInstance() returns one    |
|           |                                      | 4. Add thread-safety if needed         |
