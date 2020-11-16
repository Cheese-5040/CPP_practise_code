#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int length;
// You'll be given an array of N integers and you have to print the integers in the reverse order.


int main() {
    cin >> length;
    int arr[length];
    for(int i=0;i<(length);i++){
        cin >> arr[i] ;// input the list, element by element using a for loop
    }
    for(int i=0;i<(length);i++){
        cout <<  arr[length-1 -i] << " "; //reverse the orrder of the list by printing frorm the last element to the first 
    }
    return 0;
}
