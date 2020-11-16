#include <iostream>
#include <cstring>
using namespace std;

int plusfunction (int x, int y){
    return x+y;
}
double plusfunction (double x, double y){
    return x+y;
}
int main (){
    int num1=plusfunction (10,21);
    double num2= plusfunction (3.21, 4.56);
    cout<< "int : " << num1 << endl;
    cout<< "double : "<< num2 << endl;
    return 0;
}