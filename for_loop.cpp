#include <iostream>
#include <cstdio>
using namespace std;
int a;
int b;
int c;
int d;
int e;

int main() {
    // take in two numbers and output accordingly
    cin >> a;
    cin >> b;
    c = b- a;
    // cout << c;
    for (int i = 0; i<=c;i++){
        d = a+i;
        // cout << d<< endl;
        // if number is less than 10, print the letter out
        if (d==1){
            cout << "one" <<endl;
        }
        else if (d==2){
            cout << "two"<<endl;
        }
        else if (d==3){
            cout << "three"<<endl;
        }
        else if (d==4){
            cout << "four"<< endl;
        }
        else if (d==5){
            cout << "five"<<endl;
        }
        else if (d==6){
            cout << "six"<<endl;
        }
        else if (d==7){
            cout << "seven"<<endl;
        }
        else if (d==8){
            cout << "eight"<<endl;
        }
        else if (d==9){
            cout << "nine"<<endl;
        }
        // if number is larger than 9, then print even or odd out 
        else if (d>9){
            e=d%2;
            if (e==1){
                cout << "odd"<<endl;
            }
            else if (e==0){
                cout << "even"<<endl;
            }
        }
        

    }
    return 0;
}