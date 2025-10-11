/*
HOMERK!!
- giv u a graf, ok?
- implement this kruskal alg using DSU data
structure

gRAPH
1 -(15)- 5 -(6)- 4 -(3)- 6                9 ---(2) ---10
| \             /        |                |      (1) /
(8)\      / (3)         (2)               (7) /
|   (7)\ /               |                | /
2- (3)--3 ---(4) ------  7 -------(4)-----8

Depositing the tuple edge list thing:
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

How to do the sort thing:

#include <algorithm>
#include <vector>
#include <iostream>

struct Person {
    string name;
    int age;
};

// Custom comparison function for sorting Person objects by age
bool comparePeopleByAge(const Person& p1, const Person& p2) {
    return p1.age < p2.age; // Sorts in ascending order of age
}

int main() {
    vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    sort(people.begin(), people.end(), comparePeopleByAge);

    for (const auto& p : people) {
        cout << p.name << " " << p.age << endl;
    }
    return 0;
}


// Access the third element (index 2)
int thirdElement = get<2>(myTuple); 
*/

#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};
int n = 10;
vector<int> link(n+1);
vector<int> chonkSize(n+1);
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (chonkSize[a] < chonkSize[b]) swap(a,b);
    chonkSize[a] += chonkSize[b];
    link[b] = a;
}
bool compareEdgesByWeight(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight; // Sorts in ascending order of weight :)
}
int main(){
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) chonkSize[i] = 1;
    vector<Edge> edges;
    // initialize the edge list representation of the graph
    edges.push_back(Edge(1, 2, 8));
    edges.push_back(Edge(1, 3, 7));
    edges.push_back(Edge(1, 5, 15));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(3, 4, 3));
    edges.push_back(Edge(3, 7, 4));
    edges.push_back(Edge(4, 5, 6));
    edges.push_back(Edge(4, 6, 3));
    edges.push_back(Edge(6, 7, 2));
    edges.push_back(Edge(7, 8, 4));
    edges.push_back(Edge(8, 9, 7));
    edges.push_back(Edge(8, 10, 1));
    edges.push_back(Edge(9, 10, 2));
    // sort the stuffff
    sort(edges.begin(), edges.end(), compareEdgesByWeight);
    vector<Edge> mstEdges;
    for (int i = 0; i < edges.size(); i++){
        int a = edges[i].from;
        int b = edges[i].to;
        if (!same(a,b)) {
            unite(a,b);
            mstEdges.push_back(edges[i]);
        }
    }
    cout << "MST edges:" << endl;
    for (const Edge& e : mstEdges) {
        cout << e.from << " - " << e.to << " (weight: " << e.weight << ")" << endl;
    }
    cout << endl;
    return 0;
}