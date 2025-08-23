/*
HOMEWORK!!!!
2 input:
1. # nodes
create random graph
2. max edges per node :)
use djikstra's algorithm to compute shortest path from node 0 to
3. pancake (node where the pancake iz)
*/
#include <vector>
#include <utility>
#include <iostream>
#include <random>
#include <set>
#include <queue>

using namespace std;
long long INF = numeric_limits<long long>::max();
struct PairGreater {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.first != p2.first)
        {
            return p1.first > p2.first;
        }
        return false;
    }
};

void yeet_dupes_out_window(vector<pair<int, int>> &vectorTM){
    set<pair<int, int>> setTM;
    for (auto elem : vectorTM){
        setTM.insert(elem);
    }
    vectorTM.clear();
    for (auto elem : setTM){
        vectorTM.push_back(elem);
    }
}
int main(){
    cout << "Total nodes for the graph:" << endl;
    int numNodes;
    cin >> numNodes;
    vector<long long> distance(numNodes);
    cout << "Maximum edges per node: " << endl;
    int maxEdges;
    cin >> maxEdges;
    vector<vector<pair<int,int>>> adj_list(numNodes);
    bool visited[numNodes];
    for (int i = 0; i < numNodes; i++){
        visited[i] = false;
    }

    for (int p = 0; p < numNodes; p++){
        int num_neighbors = rand() % maxEdges;
        if (num_neighbors == 0) num_neighbors = 1;
        for (int q = 0; q < num_neighbors; q++){
            int m = rand() % numNodes;
            if (m==p){
                m = (m+1) % numNodes;
            }
            int w = rand() % 11;
            if (w==0){
                w = 1;
            }
            adj_list[p].push_back(pair<int, int> (m, w));
        }
        yeet_dupes_out_window(adj_list[p]);
    }
    for (int u = 0; u < numNodes; u++) {
        for (auto v : adj_list[u]){
            cout << "[" << u << "] --- [" << v.first << ", " << v.second << "]\n";
        }
    }
    priority_queue<pair<int,int>, vector<pair<int, int>>, PairGreater> q;
    for (int i = 1; i < numNodes; i++) distance[i] = INF;
    distance[0] = 0;
    q.push({0,0});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : adj_list[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({distance[b], b});
            }
        }
    }
    cout << "What is the destination? Must be an integer less than the number of nodes " << endl;
    int pancake;
    cin >> pancake;
    cout << "Shortest path from first to destination node: " << endl;
    cout << distance[pancake] << endl;
    return 0;

}