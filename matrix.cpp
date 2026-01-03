#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int main() {
    int n = 6;          // nodes 1..6
    int L = 4;          // exactly 4 edges

    // dist[len][i][j] = shortest distance from i to j using exactly len edges
    vector<vector<vector<int>>> dist(L + 1, vector<vector<int>>(n, vector<int>(n, INF)));

    // nxt[len][i][j] = first node after i on a shortest path from i to j using exactly len edges
    vector<vector<vector<int>>> nxt(L + 1, vector<vector<int>>(n, vector<int>(n, -1)));

    // Base: exactly 1 edge
    // IMPORTANT: diagonal is INF here (no free 0-edge staying put),
    // because we are counting EXACT edges.
    auto add_edge = [&](int u, int v, int w) {
        dist[1][u][v] = w;
        nxt[1][u][v] = v;
    };

    // Your directed weighted edges (convert 1-based to 0-based)
    add_edge(0, 3, 4); // 1->4 (4)
    add_edge(1, 0, 2); // 2->1 (2)
    add_edge(1, 4, 1); // 2->5 (1)
    add_edge(1, 5, 2); // 2->6 (2)
    add_edge(2, 1, 4); // 3->2 (4)
    add_edge(3, 1, 1); // 4->2 (1)
    add_edge(5, 2, 3); // 6->3 (3)
    add_edge(5, 4, 2); // 6->5 (2)

    // Build dist[2], dist[3], dist[4] by extending with one more edge each time:
    // dist[len][i][j] = min_k dist[len-1][i][k] + dist[1][k][j]
    for (int len = 2; len <= L; len++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (dist[len - 1][i][k] >= INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[1][k][j] >= INF) continue;

                    int cand = dist[len - 1][i][k] + dist[1][k][j];
                    if (cand < dist[len][i][j]) {
                        dist[len][i][j] = cand;
                        nxt[len][i][j] = nxt[len - 1][i][k]; // first hop comes from the (len-1)-edge part
                    }
                }
            }
        }
    }

    // Print distance matrix for exactly 4 edges
    cout << "Shortest distances using exactly 4 edges:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[4][i][j] >= INF) cout << "INF ";
            else cout << dist[4][i][j] << " ";
        }
        cout << "\n";
    }

    // Print ONE valid 4-edge path: pick the first (i,j) that is reachable with 4 edges
    int start = -1, goal = -1;
    for (int i = 0; i < n && start == -1; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[4][i][j] < INF) {
                start = i;
                goal = j;
                break;
            }
        }
    }

    if (start == -1) {
        cout << "\nNo path of exactly 4 edges exists in this graph.\n";
        return 0;
    }

    // Reconstruct: each step reduces remaining edges
    cout << "\nOne path of 4 edges:\n";
    int cur = start;
    cout << (cur + 1);
    for (int remaining = 4; remaining >= 1; remaining--) {
        cur = nxt[remaining][cur][goal];
        if (cur == -1) { // safety check (shouldn't happen if dist is reachable)
            cout << "\nPath reconstruction failed unexpectedly.\n";
            return 0;
        }
        cout << " -> " << (cur + 1);
    }
    cout << "\n(total weight = " << dist[4][start][goal] << ")\n";

    return 0;
}
