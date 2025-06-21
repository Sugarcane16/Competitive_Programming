/*
input:
1. array size -> n
then output that array with random value
from 1 to 100
2. 2 indexes for range. calculate sum of that
subarray
3. give another index and value u want to change it to
calculate the same thing (sum of subarray. AGAIN)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <random>
using namespace std;
int n, a, b;
int sum(int k, int* tree) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}
int calcRangeSum(int k, int* arr) {
    int s = 0;
    int end_index = k - (k&-k);
    for (int i = end_index + 1; i <= k; i++){
        s += arr[i];
    }
    return s;
}
void add(int k, int x, int* tree) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}
int main(){
    cout << "Please enter the last index of your array: ";
    cin >> n;
    int* arr = new int[n + 1];
    int* tree = new int[n + 1];
    int* sum_array = new int[n + 1];
    cout << "Here is your array: ";
    // Initialize and use the array
    random_device rd;
    mt19937 gen(rd()); // Create and seed the generator once
    uniform_int_distribution<int> distribution;
    for (int i = 1; i < n + 1; ++i) {
        int randomNumber = distribution(gen); // Generate random number
        arr[i] = randomNumber % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        tree[i] = calcRangeSum(i, arr);
    }

    cout << "The array tree is as follows:" << endl;
    for (int i = 1; i <= n; i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    // now get da SUM >:(
    cout << "The sum array is as follows:" << endl;
    for (int i = 1; i <= n; i++){
        sum_array[i] = sum(i, tree);
        cout << sum_array[i] << " ";
    }
    cout << "Please enter a and b, the start and end indexes for the subarray, with a being less than b: " << endl;
    cin >> a >> b;
    cout << "a and b are, respectively, " << a << " and " << b << endl;
    if (a <= n && b <= n && a > 0 && b >= 0 && a < b){
        int a_b_sum = sum_array[b] - sum_array[a - 1];
        cout << "The sum of all the values between index a and b, inclusive, is " << a_b_sum << endl;
    } else{
        cout << "Invalid input detected: either a and/or b are out of bounds for the array index values, or a is not less than b, or both. pls try again. :(";
    }
    cout << "Now pls input another index c between a and b, and the value you want to change it to (d): ";
    int c, d;
    cin >> c >> d;
    if (c >= a && c <= b){
        int x = d - arr[c];
        add(c, x, tree);
        for (int i = 1; i <= n; i++){
            sum_array[i] = sum(i, tree);
        }
        cout << "This is x : " << x << endl;
        cout << "Now the new array is: " << endl;
        for (int i = 1; i <= n; i++){
            cout << sum_array[i] << " ";
        }
        cout << endl;
        int new_a_b_sum = sum_array[b] - sum_array[a - 1];
        cout << "The updated sum of all the values between index a and b, inclusive, is " << new_a_b_sum << endl;
    } else{
        cout << "Invalid input detected: c is not an index between indices a and b, inclusive. pls try again. :(";
    }
    
    delete[] arr;
    delete[] tree;
}
