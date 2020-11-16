#include <iostream>
#include <cstring>
using namespace std;

int main () {
    string food = "babi";
    string &meal = food ; //alias of food, points to same value inside food -> babi 
    cout << food << endl;
    cout << meal << endl;

}