#include <iostream>
#include <string>
using namespace std;

// How to reverse a character array :) My mom is OCD ;)

void reverse(char array[], int start_index, int end_index){
    for (int n = start_index; n < (start_index + end_index) / 2; n++) {
        int m = end_index + start_index - n;
        char a = array[n];
        array[n] = array[m];
        array[m] = a;
    }
}

int main() {
    char array[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "The current array is: " << array << endl;
    reverse(array, 0, 4);
    cout << "The reversed array is: " << array << endl;
}