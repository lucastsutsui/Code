#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int n,m;
int mark[123];

bool dfs(vector<vector<int> > graph, int i, int color){
    if (mark[i] != -1) return mark[i] == color;
    
    mark[i] = color;
    
    for (int j = 0; j < graph[i].size(); j++) 
        if (!dfs(graph, graph[i][j], (color+1)%2)) return false;
        
    return true;
}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int u,v,inst=1;
	
	while (cin >> n >> m){
	    vector<vector<int> > graph(n);
	    
	    for (int i = 0; i < m; i++){
	        cin >> u >> v; u--; v--;
	        graph[u].push_back(v);
	        graph[v].push_back(u);
	    }
	    
	    for (int i = 0; i < n; i++) mark[i] = -1;
	    
	    bool answer = true;
	    for (int i = 0; i < n; i++) if (mark[i] == -1 && !dfs(graph, i, 0)) answer = false;
	    
	    cout << "Instancia " << inst++ << el;
	    cout << (answer ? "sim\n\n" : "nao\n\n");
	}
	
    return 0;
}