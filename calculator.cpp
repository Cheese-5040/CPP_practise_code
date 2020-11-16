#include <iostream>
using namespace std;

int main () {
    cout << "please enter the first number\n";
    double x;
    cin >> x;
    cout << "please enter the second number\n";
    double y;
    cin >> y;
    cout << "please enter operator";
    char sign;
    cin >> sign;
    if (sign == '+') {
        cout << x + y;
    }
    else if (sign == '-'){
        cout << x-y;
    }
    else if (sign == '*'){
        cout << x*y;
    }
    else if (sign == '/'){
        cout << x/y;
    }
    else {
        cout<<"error";
    }
}