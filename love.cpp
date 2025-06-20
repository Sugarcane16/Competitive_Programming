#include <iostream> 
#include <fstream> 
using namespace std; 

int main () { 
    ofstream myfile;
    myfile.open ("/Users/maohualu/Cynthia_Coding/love.txt", ios::out); 
    for (int n=100; n>0; n-- ) {
        myfile << "I love you, mama!\n\n\n\n" << "I love you too, daddy!\n\n\n\n" << "I love my sister, also\n\n\n\n";
    }
    myfile.close(); 
    return 0; 
}