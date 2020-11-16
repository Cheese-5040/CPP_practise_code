#include <iostream>
using namespace std;

int main (){
    for (int i =0; i<10; i++){
        // for statement 1, statement 2, statement 3, do _____
        // in this case, for interger i from 0, increment i until it is less than 5
        
        if (i==9){
            cout << "this will break now \n";
            break ;
        }
        if (i==6){
            cout << "this will continue and skip \n";
            continue;
        }
    cout<<i<<"\n";
    }
}