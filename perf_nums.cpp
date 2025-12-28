#include <iostream>
using namespace std;
//1. given input n, find out if there are perfect numbers smaller than n. if so, output them.
bool isPerf(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    cout << "First part: Check for perfect numbers less than the input!" << endl;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;
    if (n <= 6){
      cout << "There are no perfect numbers less than " << n << ".";
    } else {
      cout << "Listed are all the perfect numbers less than " << n << ":" << endl;
      for (int i = 2; i < n; i++) {
        if (isPerf(i)) cout << i << endl;
      }
    }

    //2. Given 2 numbers, compute the gcd AND lcm of the two. and print them.
    cout << "Next: Given 2 numbers as input, print the GCD and LCM! :)" << endl;
    int a, b;
    cout << "Enter 2 numbers separated by spaces: ";
    cin >> a >> b;
    int x = gcd(a, b); // had to change to x otherwise there would be an error :(
    int y = a * b / x; // mirror the x-change. otherwise i would hv named this lcm but whatever its ok
    cout << "The GCD of " << a << " and " << b << " is " << x << "." << endl;
    cout << "The LCM of " << a << " and " << b << " is " << y << "." << endl;
    return 0;
}
