#include <iostream>
#include <cstring>
using namespace std;
// class is a template for objects, and object is an instance of class
// eg: fruit is a class, and banana, apple is an object part of class fruit

//similar to functions, can define first then call later when needed in the main loop
class fruits
{                  //the class
public:            //access specifier, tells if the members of class is accessible outside the class
    string colour; // (variable) attribute of class
    int number;    // (variable) another attribute of the class
    string name;   // another attribute of the class
    string type;   // another attribute of the class FF
    string babi;
    void interest(){//have a function in a class
        cout << "i like fruits" << endl;
    }
    void interest1();
};

void fruits::interest1(){ // define function outside class
    cout << "watashi daisuki fruits" << endl;

}
int main()
{
    fruits object1; //create an object of fruits

    //    access attributes and set values for the object
    object1.name = "banana";
    object1.colour = "yellow";
    object1.number = 12;
    object1.type = "berry";
    object1.interest(); //access function in class by using objet in class with dot (.)
    object1.interest1(); //access function in class
    fruits object2; //create another object of fruits

    //    access attributes and set values for the other object
    object2.name = "strawberry";
    object2.colour = "red";
    object2.number = 5;
    object2.type = "berry";

    

    cout << "i want to buy a " << object1.name << " which is " << object1.colour << \
    " and a " << object1.type << ".  I need to buy " << object1.number << " of them.  "<<endl;
    cout << "i want to buy a " << object2.name << " which is " << object2.colour << \
    " and a " << object2.type << ".  I need to buy " << object2.number << " of them.  "<<endl;

    return 0;
}
