#include <iostream>
#include <cstdio>
using namespace std;
// this program will print the input of integer, long, character, float and double individually after entering them as a string in the first input

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d \n %ld \n %c \n %f \n %lf", a, b, c, d, e);
    return 0;
}
