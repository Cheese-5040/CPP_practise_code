#include <iostream>
#include <cmath>
using namespace std;
int sum;
int absdiff;

void update(int *a,int *b) { // take the values from each pointer
    *a += *b; // add both values from both pointers
    *b = abs(*a-2**b); // get the difference of both values from pointer and modulus 
}

int main() {
    int a, b;
    int *pa = &a; //pointer declaration, let memory address of integer a be pointer pa
    int *pb = &b; 
    cin >> a;
    cin >> b;
    cout<< pa << endl; // output the memory address pointing to variable"a"
    cout<< &pa << endl; // output the memory address of variable pa?
    cout<< *pa << endl; // output the value of the variable "a" as it is assigned to pointer pa
    cout<< a << endl; // output the value of "a"
    cout<< &a << endl; // output the memory address of "a" 
    // cout<< *a << endl; 
    update(pa, pb);
    cout << a << endl;
    cout << b << endl;

    return 0;
}