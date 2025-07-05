/*listen carefully!
the question is:
given u an array of arbitrary size which is input from user (again)
u hafta do delete
convert to array of 2^n which is leaf node array right
then construct a segment tree to XOR OPERATION >:( insert angry noises here
support 2 operations: given range of input, find boolean value, update*/
#include <iostream>
#include <vector>
#include <utility>
#include <random>
using namespace std;
int getSizeofSecondArray(int n){
    int k = 0;
    int two_to_power_of_k = 1;
    while (n > two_to_power_of_k){
        k++;
        two_to_power_of_k *= 2;
    }
    return k;
}
bool xorEverythinginTheRange(int a, int b, bool* tree, int arr_size){
    a += arr_size; b += arr_size;
    bool s;
    bool s_initialized = false;
    while (a <= b) {
        if (a%2 == 1){
            if (!s_initialized){
                s = tree[a++];
                s_initialized = true;
            } else{
                s ^= tree[a++];
            }
        }
        if (b%2 == 0){
            if (!s_initialized){
                s = tree[b--];
                s_initialized = true;
            } else{
                s ^= tree[b--];
            }
        } 
        a /= 2; b /= 2;
    }
    return s;
}
void update(int k, bool x, bool* tree, int arr_size) {
    k += arr_size;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k] ^ tree[2*k+1];
    }
}
int main(){
    int n;
    cout << "Please enter the size of your array: ";
    cin >> n;
    bool* arr = new bool[n];
    int k = getSizeofSecondArray(n);
    int two_pwr_arr_size = 1 << k;
    bool* two_power_arr = new bool[two_pwr_arr_size];
    bool* tree = new bool[2*two_pwr_arr_size];
    
    cout << "Here is your array: ";
    // Initialize and use the array
    random_device rd;
    mt19937 gen(rd()); // Create and seed the generator once
    uniform_int_distribution<int> distribution;
    for (int i = 0; i < n; ++i) {
        int randomNumber = distribution(gen); // Generate random number
        int val = randomNumber % 2;
        if (val == 1){
            arr[i] = true;
        } else{
            arr[i] = false;
        }
        two_power_arr[i] = arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = n; i < two_pwr_arr_size; i++){
        two_power_arr[i] = false;
    }
    cout << "this is the two power array: ";
    for (int i = 0; i < two_pwr_arr_size; i++){
        cout << two_power_arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= two_pwr_arr_size; i++){
        tree[i+two_pwr_arr_size] = arr[i];
    }
    int start_ind = two_pwr_arr_size;
    for (int i = k - 1; i >= 0; i--){
        int size = 1 << i;
        start_ind /= 2;
        for (int j = start_ind + 1; j <= start_ind + size; j++){
            tree[j] = tree[2*j] ^ tree[2*j + 1];
        }
    }
    cout << "k is " << k;
    cout << "This is the tree: ";
    for (int i = 1; i < 2*two_pwr_arr_size; i++){
        cout << tree[i] << " ";
    }

    cout << endl;
    cout << "Please enter a and b, the start and end indexes for the subarray, with a being less than b: " << endl;
    int a, b;
    cin >> a >> b;
    cout << "a and b are, respectively, " << a << " and " << b << endl;
    if (a <= n && b <= n && a > 0 && b >= 0 && a < b){
        bool a_b_sum = xorEverythinginTheRange(a, b, tree, two_pwr_arr_size);
        cout << "The xor of all the values between index a and b, inclusive, is " << a_b_sum << endl;
    } else{
        cout << "Invalid input detected: either a and/or b are out of bounds for the array index values, or a is not less than b, or both. pls try again. :(";
    }
    cout << "Now pls input another index c between a and b, and the value you want to change it to (d): ";
    int c;
    bool d;
    cin >> c >> d;
    if (c >= a && c <= b){
        update(c, d, tree, two_pwr_arr_size);
        cout << "Now the new values are: " << endl;
        for (int i = 1; i < 2*n; i++){
            cout << tree[i] << " ";
        }
        bool new_a_b_sum = xorEverythinginTheRange(a, b, tree, two_pwr_arr_size);
        cout << endl;
        cout << "The updated xor of all the values between index a and b, inclusive, is " << new_a_b_sum << endl;
    } else{
        cout << "Invalid input detected: c is not an index between indices a and b, inclusive. pls try again. :(";
    }
    
    delete[] arr;
    delete[] two_power_arr;
    delete[] tree;
}
