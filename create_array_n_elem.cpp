#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> vec(n);

    // Seed random number generator
    srand(time(0));

    // Fill the vector with random values in range [0, 2n]
    for (int i = 0; i < n; ++i) {
        vec[i] = rand() % (2 * n + 1);
    }

    // Print the generated vector
    cout << "Generated vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
