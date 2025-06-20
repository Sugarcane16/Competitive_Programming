// shortest path using BFS and struct
// your output should be 9

#include<bits/stdc++.h>
#define N 5
using namespace std;

int maze[N][N] = {{0,0,0,0,0 },
                  {0,1,1,1,0 },
                  {0,1,0,0,0 },
                  {0,1,0,1,0 },
                  {0,0,0,1,0 } };
                
int visited[N][N];
                     
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int sx = 0, sy = 0, ex = N-1, ey = N-1;

struct point {
	int x, y, s; // s: step
	point(int a, int b, int c) : x(a), y(b), s(c) {}
};


queue<point> q;

int main() {
    visited[sx][sy] = 1;
    q.push(point(sx, sy, 1));
	
	while(!q.empty()) {
        point pt = q.front();
        q.pop(); // remove front 
		
		
    	}
 
   cout << "No solution"; // if can't reach end point
}