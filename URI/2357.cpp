#include <bits/stdc++.h>
using namespace std;

int n,m;
bool ans;
bool visited[10001];
vector<vector<int> > graph(10001);

void dfs(int fat, int i){
    visited[i] = true;
    for (int j = 0; j < graph[i].size(); j++){
        if (!visited[graph[i][j]]) dfs(i, graph[i][j]);
        else if (graph[i][j] != fat) ans = false;
    }
}

int main() 
{
    int a, b;
    
    while (scanf ("%d %d", &n, &m) != EOF){
        for (int i = 0; i < n; i++) graph[i].clear();
        ans = true;
        
        for (int i = 0; i < m; i++){
            scanf("%d %d", &a, &b); a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for (int i = 0; i < n; i++) visited[i] = false;
        for (int i = 0; i < n; i++) if (ans && !visited[i]) dfs(-1, i);
        
        if (ans) puts("Seguro");
        else puts("Inseguro");
    }
    
    return 0;
}
