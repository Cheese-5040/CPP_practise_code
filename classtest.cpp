#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
int null = 0;
class headphones
{
public:
    string name;
    string brand;
    int price;
    // string colours;
    // void colour()
    // {
    //     cout << "what is the desired colour of the headphone" << endl;
    //     cin >> colours;
    //     if (colours == "blue")
    //     {
    //         cout << "it is not available"<< endl;
    //     }
    //     else
    //     {
    //         cout << "Yes "<< colours << " is available"<< endl;
    //         cout << " the headphone is :"<< name << endl;
    //         cout << " the headphone brand is :" << brand << endl;
    //         cout << " the price is :" << price << endl;
    //     }
    //    return;
    //}
};
int main (){
    headphones testSample[3];
    for (int i = 0;i < 3;i++){
        cout << i << endl;
        headphones headphone;
        cout << "please input the headphone name"<< endl;
        cin >> headphone.name;
        cout << "input brand of headphone" << endl;
        cin >> headphone.brand;
        cout << "enter price of headphone" << endl;
        cin >> headphone.price;
        cout<<"price is of type: "<<typeid(headphone.price).name()<<endl; // Output type of variable
        testSample[i] = headphone;
    }
    // if (testSample[0].price>testSample[1].price and testSample[0].price >testSample[2])
    return 0;
}