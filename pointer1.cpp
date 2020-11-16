#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string food = "babi";
    string mood = "babu";
    // "*" is used to assign a pointer variable that points to the memory address of a "string" variable, in this case.
    // "&" operator is used to store memory address of the variable, and assign it to the pointer.
    string *ptr = &food; //assign pointer ptr to food address
    string *ptr1 = &mood; //assign pointer ptr1 to mood address
    cout << food << endl;  //print value of food variable
    // babi
    cout << &food << endl; //print memory address of food variable
    // some hex with dd0
    cout << mood << endl;
    // babu
    cout << &mood << endl;
    // some other hex db0
    cout << *ptr << endl; // DEREFERENCING same thing as print the value in food
    cout << *ptr1 << endl; // DEREFERECING same thing as print value in mood
    *ptr1 = *ptr; //mood value change to same value in food variable, so mood will output babi
    cout << ptr1 << endl
         << "the address for ptr1 is still pointing to mood " << endl; //REFERENCE output hex using pointer with db0
    cout << *ptr1 << endl
         << "the value of mood is changed to babi" << endl; //should output babi instead of babu for pointer for ptr1
    ptr1 = ptr; //change the memory address of ptr11 to variable food (ptr), therefore output babi also but the variable for ptr1 address change to food
    cout << ptr1 << endl
         << "the address of ptr1 changes to ptr, so it will point to variable food which contains babi" << endl; //hex with dd0 will be shown
    cout << *ptr1 << endl
         << "the value of food is babi, so babi is outputted" << endl; // babi will be output

}