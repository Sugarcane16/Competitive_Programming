#include <iostream>
#include <string>
using namespace std;

int add(int a, int &b){
    b += a;
    a += b;
    return a;
}

int main() {
    int a = 2;
    int c = 3;
    int d = add(a, c);
    cout << a << ";" << c << ";" << d << endl;
}