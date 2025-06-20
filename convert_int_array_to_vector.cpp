#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    vector<int> vec(arr, arr + 5);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}
