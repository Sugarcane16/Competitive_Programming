#include <iostream>
#include <vector>
#include <utility>
#include <random>
using namespace std;

int n;
pair<int, int> a, b, c, d;

int main(){
    cout << "Please enter n: \n \n";
    cin >> n;
    // Allocate memory for rows (an array of int pointers)
    int** arr = new int*[n];

    // Allocate memory for each column in each row
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }

    // Initialize and use the array
    random_device rd;
    uniform_int_distribution<int> distribution;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mt19937 gen(rd());
            int randomNumber = distribution(gen);
            arr[i][j] = randomNumber % 10;
        }
        cout << endl;
    }
    // must go up and left
    // up -> value alr there
    // left -> sum it up. it's only for dat row.
    int** psa = new int*[n];

    // Allocate memory for each column in each row
    for (int i = 0; i < n; ++i) {
        psa[i] = new int[n];
    }

    // Initialize and use the array
    
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            // go up
            int up_value = 0;
            if (i > 0) {
                up_value = psa[i - 1][j];
            }
            // go left
            sum += arr[i][j];
            psa[i][j] = sum + up_value;
        }
    }

    // print out the original array before giving sum of subarray
    cout << "Original array: \n \n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    // print out the PSA before giving sum of subarray
    cout << "Prefix sum array: \n \n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << psa[i][j] << " ";
        }
        cout << "\n";
    }
    

    cout << "Please enter the coordinates of A, B, C, and D, one pair on each line: \n \n";
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;
    
    cout << "The coordinates of A are " << a.first << " " << a.second << endl;
    cout << "The coordinates of B are " << b.first << " " << b.second << endl;
    cout << "The coordinates of C are " << c.first << " " <<  c.second << endl;
    cout << "The coordinates of D are " << d.first << " " << d.second << endl;
    
    int final_sum = 0;
    if (a.first < n && a.second < n){
        int s_a = psa[a.first][a.second];
        cout << s_a << endl;
        final_sum += s_a;
    } else {
        cout << "Invalid input detected: One or more of your coordinates for A are greater than n.";
        return -1;
    }
    if (b.first < n && b.second < n){
        int s_b = psa[b.first][b.second];
        cout << s_b << endl;
        final_sum -= s_b;
    } else {
        cout << "Invalid input detected: One or more of your coordinates for B are greater than n.";
        return -1;
    }
    if (c.first < n && c.second < n){
        int s_c = psa[c.first][c.second];
        cout << s_c << endl;
        final_sum -= s_c;
    } else {
        cout << "Invalid input detected: One or more of your coordinates for C are greater than n.";
        return -1;
    }
    if (d.first < n && d.second < n){
        int s_d = psa[d.first][d.second];
        cout << s_d << endl;
        final_sum += s_d;
    } else {
        cout << "Invalid input detected: One or more of your coordinates for D are greater than n.";
        return -1;
    }

    
    cout << "The sum of the area enclosed by A, B, C, and D is " << final_sum << endl;
    // Deallocate memory
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    // Deallocate more memory :|
    for (int i = 0; i < n; ++i){
        delete[] psa[i];
    }
    delete[] psa;
    return 0;
}