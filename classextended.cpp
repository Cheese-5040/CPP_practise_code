#include <iostream>
#include <cstring>
using namespace std;

class car
{
public:
    int speed(int maxspeed); //adding parameters maxspeed to variable speed in class car
};

int car::speed(int maxspeed)
{
    return maxspeed; // return the value of maxspeed when the variable speed is called
}

int main()
{
    car myobject;                        //create an object in car class
    cout << myobject.speed(200) << endl; // output the variable speed with parameters maxspeed to be 200
    return 0;
}