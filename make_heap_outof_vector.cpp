#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTopIElements(vector<int> nums, int i) {
    vector<int> topElements;

    // Step 1: Convert the vector into a max heap
    make_heap(nums.begin(), nums.end());

    // Step 2: Extract the top i elements
    for (int j = 0; j < i; j++) {
        pop_heap(nums.begin(), nums.end()); // Moves max element to the end
        topElements.push_back(nums.back()); // Store the largest element
        nums.pop_back(); // Remove it from the heap
    }

    return topElements;
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

    int i = 4; // Find top 4 elements

    vector<int> topI = findTopIElements(nums, i);

    cout << "Top " << i << " elements: ";
    for (int num : topI) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
