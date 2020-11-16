#include <iostream>
using namespace std;

main () {
    int x=2, y=4, z=10;
    // declare multiple variables in one type together in one line 
    cout << x << "\n";
    cout << y <<"\n";
    cout << z;
    const int sec_per_min=60;
    // const is used for constant variables, cannot change once constant is declared
    cout << sec_per_min;
    cout << "enter your name";
    string name ;
    cin >> name;
    // cin >> means input something and store it in the variable declated before 
    cout << "your name is "<< name;


}