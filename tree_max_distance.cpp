#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> down, up, ans;

int dfsDown(int node, int parent) {
    down[node] = 0;
    for (int child : adj[node]) {
        if (child != parent) {
            down[node] = max(down[node], dfsDown(child, node) + 1);
        }
    }
    return down[node];
}

void dfsUp(int node, int parent) {
    vector<int> childDistances;
    
    for (int child : adj[node]) {
        if (child != parent) {
            childDistances.push_back(down[child] + 1);
        }
    }
    
    sort(childDistances.rbegin(), childDistances.rend());
    
    for (int child : adj[node]) {
        if (child != parent) {
            int maxFromParent = up[node];
            
            for (int dist : childDistances) {
                if (dist != down[child] + 1) {
                    maxFromParent = max(maxFromParent, dist);
                    break;
                }
            }
            
            up[child] = maxFromParent + 1;
            dfsUp(child, node);
        }
    }
    
    ans[node] = max(down[node], up[node]);
}

int main() {
    adj.resize(12);
    down.resize(12);
    up.resize(12);
    ans.resize(12);
    
    // 1
    // |  \
    // 3  2
    // |  | \
    // 4  5  6
    //   / \  \
    //  7  8   9
    // /        \
    // 10       11
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(6);
    adj[6].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[5].push_back(7);
    adj[7].push_back(5);
    adj[5].push_back(8);
    adj[8].push_back(5);
    adj[6].push_back(9);
    adj[9].push_back(6);
    adj[7].push_back(10);
    adj[10].push_back(7);
    adj[9].push_back(11);
    adj[11].push_back(9);
    
    dfsDown(1, -1);
    up[1] = 0;
    dfsUp(1, -1);
    
    cout << "Maximum path length from each node:\n";
    for (int i = 1; i <= 11; i++) {
        cout << "Node " << i << ": " << ans[i] << "\n";
    }
    
    return 0;
}