#include<bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int n,m;

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2); // same as cin >> v1 >> v2;
		if(v1==v2) continue;
		g[v1].push_back(v2);
		//g[v2].push_back(v1); // if undirected graph
	}
	
	for(int i=1; i<=n; i++) {
	    printf("%d: ", i);
	    for(int j=0; j<g[i].size();j++)
	        printf("%d ", g[i][j]);
	    printf("\n");
	}
	return 0;
}