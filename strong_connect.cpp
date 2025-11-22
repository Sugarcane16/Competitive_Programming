#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;
/*
homewerk!!!
with the directed graph last week, find out all the
strongly connected component of the graph and print it out
*/
struct Edge { // make the crusty structure thing
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

void dfs1(int u, vector<vector<int> >& adj, vector<bool>& visited, stack<int>& finishOrder) {
    // first dfs
    visited[u] = true; // mark u as visited
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i]; // put inside adj
        if (!visited[v]) {
            dfs1(v, adj, visited, finishOrder); // recursion
        }
    }
    finishOrder.push(u); // put u in for the finishOrder thing
}

void dfs2(int u, vector<vector<int> >& revAdj, vector<bool>& visited, vector<int>& component) {
    // 2nd round :)
    visited[u] = true;
    component.push_back(u); // put into component
    for (int i = 0; i < revAdj[u].size(); i++) {
        int v = revAdj[u][i]; // put into revAdj
        if (!visited[v]) {
            dfs2(v, revAdj, visited, component); // recursion
        }
    }
}

int main(){
    int n = 10;
    vector<vector<int> > adj(n+1);
    vector<vector<int> > revAdj(n+1);
    
    vector<Edge> edges;
    // initialization of the crusty musty dusty rusty graph
    edges.push_back(Edge(1, 5, 15));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(3, 7, 4));
    edges.push_back(Edge(5, 4, 6));
    edges.push_back(Edge(4, 6, 3));
    edges.push_back(Edge(6, 7, 2));
    edges.push_back(Edge(7, 8, 4));
    edges.push_back(Edge(9, 7, 7));
    edges.push_back(Edge(8, 10, 1));
    edges.push_back(Edge(10, 9, 2));
    
    // Build adjacency list and reverse adjacency list
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].from].push_back(edges[i].to);
        revAdj[edges[i].to].push_back(edges[i].from);
    }
    
    // Kosaraju's Algorithm
    // Step 1: First DFS to get finishing order
    vector<bool> visited(n+1, false);
    stack<int> finishOrder;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, finishOrder);
        }
    }
    
    // Step 2: Second DFS on reversed graph
    fill(visited.begin(), visited.end(), false);
    vector<vector<int> > components;
    
    while (!finishOrder.empty()) {
        int u = finishOrder.top();
        finishOrder.pop();
        
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, revAdj, visited, component);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }
    
    cout << "Strongly Connected Components:" << endl;
    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i+1 << ": ";
        for (int j = 0; j < components[i].size(); j++) {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}