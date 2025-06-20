#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findIthLargest(vector<int>& nums, int i) {
    int n = nums.size();
    
    // Use nth_element to place the ith largest element at position (n - i)
    nth_element(nums.begin(), nums.begin() + (n - i), nums.end());

    return nums[n - i];
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

    int i = 3; // Find the 3rd largest element

    int result = findIthLargest(nums, i);
    cout << "The " << i << "th largest element is: " << result << endl;

    return 0;
}
