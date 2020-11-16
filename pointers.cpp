#include <iostream>
using namespace std;

int main (){
    string headphones="sony wh-1000xm3";//variable declaration 
    string* ptr = &headphones; // pointer declaration 
    *ptr = "hello abby"; // assign headphones value to hellp abby
    cout << headphones << endl; //output the variable headphones
    cout << &headphones << endl; // output the memory address of headphones variable 
    string headphones2 ="hello kinshuk";
    *ptr = headphones2;
    // headphones = "hello abby!";
    cout << ptr << endl;
    cout << headphones << endl; // output the memory address of headphones variable 
    cout << &headphones2 << endl; // output the memory address of headphones variable 

    // a pointer stores its memory address as its value 
}
