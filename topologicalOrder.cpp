#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
/*
GRAPH
1 -(15)-> 5 -(6)-> 4 -(3)-> 6                9 ---(2) -->10
^| \             /        ^|                ^|      (1) /^
(8)\      / (3)         (2)               (7)        /
|   (7)\ /                        /                /
|       >                 |  </               /
2- (3)->3 ----(4) ----->  7 -------(4)---->8
 */
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

void dfs(int u, vector<vector<int> >& adj, vector<int>& state, vector<int>& topoOrder, bool& hasCycle) {
    if (state[u] == 1) {
        hasCycle = true;
        return;
    }
    if (state[u] == 2) return;
    
    state[u] = 1; // Mark as visiting
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v, adj, state, topoOrder, hasCycle);
        if (hasCycle) return;
    }
    state[u] = 2; // Mark as visited
    topoOrder.push_back(u);
}

int main(){
    int n = 10;
    vector<vector<int> > adj(n+1);
    vector<int> indegree(n+1, 0);
    
    vector<Edge> edges;
    // initialize the edge list representation of the graph
    edges.push_back(Edge(2, 1, 8));
    edges.push_back(Edge(1, 3, 7));
    edges.push_back(Edge(1, 5, 15));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(4, 3, 3));
    edges.push_back(Edge(3, 7, 4));
    edges.push_back(Edge(5, 4, 6));
    edges.push_back(Edge(4, 6, 3));
    edges.push_back(Edge(7, 6, 2));
    edges.push_back(Edge(7, 8, 4));
    edges.push_back(Edge(9, 7, 7));
    edges.push_back(Edge(8, 10, 1));
    edges.push_back(Edge(9, 10, 2));

    // Build adjacency list
    for (const Edge& e : edges) {
        adj[e.from].push_back(e.to);
    }
    
    // DFS-based topological sort with states
    // 0 = unvisited, 1 = visiting (in current DFS path), 2 = visited
    vector<int> state(n+1, 0);
    vector<int> topoOrder;
    bool hasCycle = false;
    
    
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            dfs(i, adj, state, topoOrder, hasCycle);
            if (hasCycle) break;
        }
    }
    
    if (hasCycle) {
        cout << "Sorry your graph is cyclic :(" << endl;
    } else {
        reverse(topoOrder.begin(), topoOrder.end());
        cout << "Topological Order: ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}