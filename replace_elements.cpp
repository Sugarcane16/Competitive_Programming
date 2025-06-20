#include <iostream>
#include <vector>
#include <numeric> // For std::adjacent_difference

using namespace std;

int replaceElements(int next, int current) {
            return (next - current) + (next * next) / 2;
    }

vector<int> transformVector(const vector<int>& a) {
    int n = a.size();
    vector<int> myVector;
    if (n < 2) return myVector; // If vector has <2 elements, return empty

    vector<int> b(n); // Correct output size (N)
    cout << "Original vector: ";
    for (int num : b) {
        cout << num << " ";
    }
    cout << endl;

    // Compute b[i] using adjacent_difference
    adjacent_difference(a.begin(), a.end(), b.begin(),
        replaceElements);a
    return b;
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(8);

    vector<int> result = transformVector(nums);

    cout << "Transformed vector: ";
    for (int i = 1; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
