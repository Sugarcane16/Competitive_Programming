#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Min Heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(50);

    // Transfer elements to Max Heap
    priority_queue<int, vector<int>, less<int> > maxHeap;
    while (!minHeap.empty()) {
        maxHeap.push(minHeap.top()); // Move elements
        minHeap.pop();
    }

    // Print Max Heap (Descending Order)
    std::cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
    return 0;
}
