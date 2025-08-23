#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<pair<int, int> > > adjList;
    
public:
    Graph(int nodes, int maxEdges) : numNodes(nodes) {
        adjList.resize(nodes);
        generateGraph(maxEdges);
    }
    
    void generateGraph(int maxEdges) {
        srand(time(NULL));
        
        for (int node = 0; node < numNodes; node++) {
            int numEdges = rand() % maxEdges + 1;
            
            vector<int> possibleNeighbors;
            for (int i = 0; i < numNodes; i++) {
                if (i != node) {
                    possibleNeighbors.push_back(i);
                }
            }
            
            random_shuffle(possibleNeighbors.begin(), possibleNeighbors.end());
            
            int actualEdges = min(numEdges, (int)possibleNeighbors.size());
            for (int i = 0; i < actualEdges; i++) {
                int neighbor = possibleNeighbors[i];
                int weight = rand() % 10 + 1;
                adjList[node].push_back(make_pair(neighbor, weight));
            }
        }
    }
    
    void printGraph() {
        cout << "\nGenerated graph with " << numNodes << " nodes:" << endl;
        for (int i = 0; i < numNodes; i++) {
            cout << "Node " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                pair<int, int> edge = adjList[i][j];
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << endl;
        }
    }
    
    pair<int, vector<int> > dijkstra(int start, int destination) {
        vector<int> distances(numNodes, INT_MAX);
        vector<int> previous(numNodes, -1);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<bool> visited(numNodes, false);
        
        distances[start] = 0;
        pq.push(make_pair(0, start));
        
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();
            
            if (visited[currentNode]) continue;
            visited[currentNode] = true;
            
            if (currentNode == destination) break;
            
            for (int i = 0; i < adjList[currentNode].size(); i++) {
                pair<int, int> edge = adjList[currentNode][i];
                int neighbor = edge.first;
                int weight = edge.second;
                
                if (!visited[neighbor]) {
                    int newDist = currentDist + weight;
                    if (newDist < distances[neighbor]) {
                        distances[neighbor] = newDist;
                        previous[neighbor] = currentNode;
                        pq.push(make_pair(newDist, neighbor));
                    }
                }
            }
        }
        
        vector<int> path;
        int current = destination;
        while (current != -1) {
            path.push_back(current);
            current = previous[current];
        }
        reverse(path.begin(), path.end());
        
        if (distances[destination] == INT_MAX) {
            return make_pair(INT_MAX, vector<int>());
        } else {
            return make_pair(distances[destination], path);
        }
    }
};

int main() {
    int numNodes, maxEdges, destination;
    
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    
    cout << "Enter maximum edges per node: ";
    cin >> maxEdges;
    
    cout << "Enter destination node (0 to " << numNodes - 1 << "): ";
    cin >> destination;
    
    if (destination < 0 || destination >= numNodes) {
        cout << "Error: Destination must be between 0 and " << numNodes - 1 << endl;
        return 1;
    }
    
    Graph graph(numNodes, maxEdges);
    graph.printGraph();
    
    int startNode = 0;
    pair<int, vector<int> > result = graph.dijkstra(startNode, destination);
    int distance = result.first;
    vector<int> path = result.second;
    
    cout << "\nShortest path from node " << startNode << " to node " << destination << ":" << endl;
    if (distance == INT_MAX) {
        cout << "No path found!" << endl;
    } else {
        cout << "Distance: " << distance << endl;
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    return 0;
}