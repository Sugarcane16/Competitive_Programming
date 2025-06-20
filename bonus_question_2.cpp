//In an integer array, find out if there are any two
//numbers that can sum up to a certain value. :)
//Return the index of the 2 numbers. Yay. <- the problem - cynthia
//Hint: 2 for loops
#include <iostream> 
using namespace std;

void find_sum(int array[], int sum, int &first_index, int &end_index, int length) {
    for(int n = 0; n < length; n++) {
        int val_a = array[n];
        for(int m = n + 1; m < length; m++) {
            if(sum - val_a == array[m]){
                first_index = n;
                end_index = m;
                return;
            }
        }
    }
}  
int main () {
    int cynthiaarray[] = {3, 64, 9, 128, 36};
    int first_index, end_index;
    find_sum(cynthiaarray, 100, first_index, end_index, 5);
    cout << "Yay! Your first index is " << first_index << endl;
    cout << "And your second index is " << end_index << endl;
} 