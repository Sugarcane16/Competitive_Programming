/*
INPUT
FROMA USER
N NUMBER
GIVA N
N PERSONA

AND X
LIMIT

AND THEN 
RANDOMLY GENERATE
WEIGHT OF PERSON
FROM 0 TO 500 :D bc caseoh exists 

THEN  CALCULATE DA
uh the wut
the the the the
the minimal rides that's needed
YES YES YES ?????
*/

#include <iostream>
#include <vector>
#include <utility>
#include <random>
using namespace std;

int main(){
    cout << "pip iz sparkly glittr noodl wif chaotic spelling :D" << endl;
    cout << "today we r guna yeet ppl onto an elevader 4 nooo weazon!!! & we guna see how many trip they take to send ev1 go whee onto da top of da building :) :)" << endl;
    int n, x;
    cout << "ok so first tell me how many ppl u wanna yeet onto elevader" << endl;
    cin >> n;
    int* weight = new int[n];
    pair<int,int> best[1<<n];
    best[0] = {1,0};
    cout << "ooki then tell me da maximum weight of da elevader. like at how much weight the elevater go fwoomp & dies :(" << endl;
    cin >> x;
    random_device rd;
    uniform_int_distribution<int> distribution;
    for (int i = 0; i < n; ++i) {
        mt19937 gen(rd());
        int randomNumber = distribution(gen);
        weight[i] = randomNumber % 500;
        cout << "weight of #" << i << ": " << weight[i] << endl;
        cout << endl;
    }
    for (int s = 1; s < (1<<n); s++) {
        // initial value: n+1 rides are needed
        best[s] = {n+1,0};
        for (int p = 0; p < n; p++) {
            if (s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if (option.second+weight[p] <= x) {
                    // add p to an existing ride
                    option.second += weight[p];
                } else {
                    // reserve a new ride for p
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    int one = 1;
    cout << "oki so pip declares: da minimum number of elevader rides u take to get ev1 up there to da top w/o da elevator going oof iz: " << best[(one<<n)-1].first << endl;
    delete[] weight;
    return 0;
}