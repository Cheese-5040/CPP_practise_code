#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d){
    if (a>b && a>c && a>d){
        return a;
    }
    if (b>a && b>c && b>d){
        return b;
    }
    if (c>a && c>b && c>d){
        return c;
    }
    if (d>a && d>b && d>c){
        return d;
    }
    return 0;
}

int main() {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    int ans = max_of_four(a, b, c, d);
    cout << ans;
    
    return 0;
}