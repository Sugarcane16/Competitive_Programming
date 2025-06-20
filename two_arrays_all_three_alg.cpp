#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <set>      // For Algorithm 1 (ordered set)
#include <unordered_set> // For Algorithm 2 (unordered_set)
#include <algorithm> // For Algorithm 3 (sorting)
#include <chrono>

using namespace std;
using namespace chrono;

// Function to generate a random vector of size 'size' with values in range [0, 2 * max(n, m)]
vector<int> generateRandomVector(int size, int maxVal) {
    vector<int> vec(size);
    unordered_set<int> a;
    for (int i = 0; i < size;) {
        int value = rand() % (10 * maxVal + 1);
        if (a.find(value) == a.end()){
            vec[i] = value;
            a.insert(value);
            ++i;
        }
    }
    
    return vec;
}

// **Algorithm 1: Using `set` (O(n log n))**
int orderedSetIntersection(const vector<int>& A, const vector<int>& B) {
    set<int> setA(A.begin(), A.end()); // Ordered set (O(n log n) insertions)
    vector<int> result;
    
    for (int num : B) {
        if (setA.find(num) != setA.end()) { // O(log n) lookup
            result.push_back(num);
        }
    }
    //sort(result.begin(), result.end());
    /* cout << "\nVector A: ";
    for (int num : A) cout << num << " ";
    cout << "\nVector B: ";
    for (int num : B) cout << num << " ";
    cout << "\nResult: ";
    for (int num : result) cout << num << " ";
    cout << endl; */


    return result.size();
}

// **Algorithm 2: Using `unordered_set` (O(n))**
int unorderedSetIntersection(const vector<int>& A, const vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end()); // Unordered set (O(n) insertions)
    vector<int> result;
    
    for (int num : B) {
        if (setA.find(num) != setA.end()) { // O(1) lookup
            result.push_back(num);
        }
    }

    /*
    cout << "\nVector A: ";
    for (int num : A) cout << num << " ";
    cout << "\nVector B: ";
    for (int num : B) cout << num << " ";
    cout << "\nResult: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    */
    
    return result.size();
}

// **Algorithm 3: Sorting + Two Pointers (O(n log n))**
int sortedIntersection(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end()); // O(n log n)
    sort(B.begin(), B.end()); // O(m log m)
    
    set<int> result;
    int i = 0, j = 0;
    
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            ++i;
        } else if (A[i] > B[j]) {
            ++j;
        } else {
            result.insert(A[i]); // Found common element
            ++i, ++j;
        }
    }
/*     cout << "\nVector A: ";
    for (int num : A) cout << num << " ";
    cout << "\nVector B: ";
    for (int num : B) cout << num << " ";
    cout << "\nResult: ";
    for (int num : result) cout << num << " ";
    cout << endl;
 */
    return result.size();
}

int main() {
    srand(time(0));  // Seed the random number generator

    int n, m;
    cout << "Enter the size of first array (n): ";
    cin >> n;
    cout << "Enter the size of second array (m): ";
    cin >> m;

    int maxVal = max(n, m);
    
    vector<int> A = generateRandomVector(n, maxVal);
    vector<int> B = generateRandomVector(m, maxVal);

    // Print the generated vectors
    //cout << "\nVector A: ";
    //for (int num : A) cout << num << " ";
    //cout << "\nVector B: ";
    //for (int num : B) cout << num << " ";
    //cout << endl;

    // **Algorithm 1: Using `set`**
    auto start1 = high_resolution_clock::now();
    int result1 = orderedSetIntersection(A, B);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "\nAlgorithm 1 (Using `set` - O(n log n)):\n";
    cout << "Number of Common Elements: " << result1 << endl;
    cout << "Time Duration: " << duration1.count() << " microseconds";
    cout << "\n-------------------------------\n";

    // **Algorithm 2: Using `unordered_set`**
    auto start2 = high_resolution_clock::now();
    int result2 = unorderedSetIntersection(A, B);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    
    cout << "Algorithm 2 (Using `unordered_set` - O(n)):\n";
    cout << "Number of Common Elements: " << result2 << endl;
    cout << "Time Duration: " << duration2.count() << " microseconds";
    cout << "\n-------------------------------\n";

    // **Algorithm 3: Sorting + Two Pointers**
    auto start3 = high_resolution_clock::now();
    int result3 = sortedIntersection(A, B);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);

    cout << "Algorithm 3 (Sorting + Two Pointers - O(n log n)):\n";
    cout << "Number of Common Elements: " << result3 << endl;
    cout << "Time Duration: " << duration3.count() << " microseconds";
    cout << "\n-------------------------------\n";

    return 0;
}
