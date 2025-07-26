/*
all of the below comment block iz daddy commentary,
recorded loyally by cynthia the chaotic 
tree haz tah be
KINNECTED
UDDERWISE IF NOT CINNECTED
... not tree
makin swence????
COMPLETE GRAPHY
(adeles hands r megaphones now cuz she sleepy)
PAY ATTENSHUN
REED DIS AGAIN
-yaps abt bipartiteness
*insert adele sleepy noise here*
CINDIA GO BACK TO UR SEAT PLZZZ

OKI TODAYS HOMEWORK IZ VERY STRAIGHTFORWARD OK??

OK
GIVEN 1 GRAPH, OK?
CODE UP THE THWEE REPREZENTATION OF DA GRAPHHHHH

FIRST GET NUMBA NODES
THEN UHHHH
CONSTRUCT SIMPLE CONNECTED GRAPH
hint: tree is simple connected graph :D
AND THEN
REPREZENT DAT SIMPLE CONNECTED GRAPH WIF 3 REPRESENTATION
-ADJ LIST
-ADJ MATRIX
-EDGE LIST
*/
#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <tuple>
using namespace std;
int main(){
    int n;
    cout << "plz giv random number: (positive only :D)" << endl;
    cin >> n;
    // make da adjacency list :)
    vector<pair <int, int> > adj_list[n];
    int adj_matrix[n][n];
    // must initialize matrix with all 0 :)
    for (int p = 0; p < n; p++){
        for (int q = 0; q < n; q++){
            adj_matrix[p][q] = 0;
        }
    }
    vector<tuple <int, int, int> > edges;
    for (int p = 0; p < n; p++){
        int m = rand() % 10;
        if (m==0){
            m++;
        }
        adj_list[0].push_back({p, m});
        adj_matrix[0][p] = m;
        edges.push_back({0,p,m});
    }
    cout << endl;
    cout << "oki, dis iz da matrix dat we hv of da awesome matrix repwezentashun dat pip haz: ";
    cout << endl;
    for (int p = 0; p < n; p++){
        for (int q = 0; q < n; q++){
            cout << adj_matrix[p][q] << " ";
        }
        cout << endl;
    }
    cout << "fank u for testing out pipz graph theory thingamajig :) u r glittery now!!" << endl;
    cout << "bye bye!!!";
    cout << endl;
    return 0;
}