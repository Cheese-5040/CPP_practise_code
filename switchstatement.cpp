#include <iostream>
using namespace std;
int babi;

int main(){
    cout << "enter a number form 1-10 \n";
    cin >> babi;
    switch (babi){
        // switch allow us to change between outputs based from variables 
        case 6:
        cout << "six";
        case 5:
        cout << "five";
        case 4:
        break;
        // exit switch 
        default:
        // if no cases shown in variable, do this 
        cout << "error";

    }

}
