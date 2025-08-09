/*
find out all connected components of graph :)
input: graph represented by adjacency list
input from user: n :) (nodes)
randomly create graph wif adjacency list

input" # of node in graph
create random simple graph
using adjacency list representation

step 2:
print it OUT :)
(cn use chat generative pre-trained transformer)
-> hard probem

GIVEN A GRAPH USING ADJACENCY REPRESENTATION,
OUTPUT OR PRINT THAT GRAPH USING ASCII CODE :)

#3 find out how many components inside that graph

*/
#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <set>
using namespace std;
void dfs(int s, vector<int> adj[], bool visited[]) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u: adj[s]) {
        dfs(u, adj, visited);
    }
}
int find_false_index(bool visited[], int n){
    for(int i = 0; i < n; i++){
        if (visited[i] == false){
            return i;
        }
    }
    return -1;
}
void yeet_dupes_out_window(vector<int> &vectorTM){
    set<int> setTM;
    for (auto elem : vectorTM){
        setTM.insert(elem);
    }
    vectorTM.clear();
    for (auto elem : setTM){
        vectorTM.push_back(elem);
    }
}
int main(){
    int n;
    int max_horses;
    cout << "plz giv random number: (positive only :D)" << endl;
    cin >> n;
    cout << "plz give another random number datz less than ur previous input" << endl;
    cin >> max_horses;
    // make da adjacency list :)
    vector<int> adj_list[n];
    bool visited[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    for (int p = 0; p < n; p++){
        int num_neighbors = rand() % max_horses;
        for (int q = 0; q < num_neighbors; q++){
            int m = rand() % n;
            if (m==p){
                m = (m+1) % n;
            }
            adj_list[p].push_back(m);
        }
        // remove the duplicates
        yeet_dupes_out_window(adj_list[p]);
    }
    cout << "dis is da art form of da adjacency list of da graph we just made! :)" << endl;
    cout << "aint it bootiful?";
    cout << endl;
    
    // make it symmetric! :) NON DIRECTIONAL!
    for (int u = 0; u < n; u++) {
        for (int v : adj_list[u]){
            adj_list[v].push_back(u);
        }
    }
    //LETS REMOVE THE TRAUMATIZED DUPLICATES
    for (int u = 0; u < n; u++){
        yeet_dupes_out_window(adj_list[u]);
    }

    for (int u = 0; u < n; u++) {
        for (int v : adj_list[u]){
            cout << "[" << u << "] --- [" << v << "]\n";
        }
    }
    int num_components = 1;
    int apple = 0;
    while (true){
        dfs(apple, adj_list, visited);
        apple = find_false_index(visited, n);
        cout << "For debugging purposes, this is apple: " << apple << endl;
        if (apple != -1){
            num_components++;
            continue;
        } else {
            break;
        }
    }
    cout << "so da number of da components in dis graph iz " << num_components << endl;
    cout << "yay!!!! :)" << endl;
}