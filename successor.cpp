#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
/*
homerk!!!!

get wutever graph last time ok?
take an input k
starting frm node 1, tell the node u get to after k stepz
*/
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};
int main(){
    int n = 10;
    vector<int> succ(n+1);
    
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
    
    // Build successor array (each node has exactly one outgoing edge)
    vector<bool> hasOutgoing(n+1, false);
    for (int i = 0; i < edges.size(); i++) {
        if (hasOutgoing[edges[i].from]) {
            cout << "Not a successor graph! Node " << edges[i].from << " has multiple outgoing edges." << endl;
            return 0;
        }
        succ[edges[i].from] = edges[i].to;
        hasOutgoing[edges[i].from] = true;
    }
    
    // Check if all nodes have exactly one outgoing edge
    for (int i = 1; i <= n; i++) {
        if (!hasOutgoing[i]) {
            cout << "Not a successor graph! Node " << i << " has no outgoing edge." << endl;
            return 0;
        }
    }
    
    cout << "Valid successor graph!" << endl;
    
    int k;
    cout << "Enter k (number of steps): ";
    cin >> k;
    
    int current = 1;
    for (int i = 0; i < k; i++) {
        current = succ[current];
    }
    
    cout << "After " << k << " steps from node 1, you reach node " << current << endl;
    
    return 0;
}