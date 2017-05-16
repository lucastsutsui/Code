#include <bits/stdc++.h>
using namespace std;

vector<int> graph[55];
int c, p, tempo, contp;
int low[55], d[55];
bitset<55> vis;

void dfs(int i, int f){
    vis[i] = 1;
    low[i] = d[i] = tempo++;
    
    for (int j = 0; j < graph[i].size(); j++){
        if (vis[graph[i][j]] == 0){
            dfs(graph[i][j], i);
            low[i] = min(low[i], low[graph[i][j]]);
            if (low[graph[i][j]] > d[i]) contp++;
        }
        else if (graph[i][j] != f) low[i] = min(low[i], d[graph[i][j]]);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int x, y;
    
    while (cin >> c >> p){
        vis.reset();
        for (int i = 0; i < c; i++) graph[i].clear();
        
        for (int i = 0; i < p; i++){
            cin >> x >> y; x--; y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        tempo = 0;
        contp = 0;
        dfs(0,0);
        
        cout << contp << '\n';
    }
    
	return 0;
}
