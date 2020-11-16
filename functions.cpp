#include <iostream>
#include <cstring>
using namespace std;

void myfunction(string fname = "cheese") // initial output of function is variable fname with value "cheese"
{                                        // void means no return value for the function
    cout << "Hello " << fname << endl;
}
int mynewfunction(int x, int y) //have x integer as the changing variable in mynewfunction()
{
    return x + y; // increment x by 5
}
int main()
{
    myfunction("babi");
    myfunction("babu");
    myfunction();
    cout << mynewfunction(3,5)<< endl; 
    // if 3 and 5 input into the mynewfunction, then 8 will be outputted 
    int z= mynewfunction(10, 21);
    cout << z << endl;
    return 0;

}
// ctrl + alt + f for making code neater