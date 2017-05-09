// Detects bridges in a connected graph

vector<int> graph[MAX];
int time, contp;
int low[MAX], d[MAX];
bitset<MAX> vis;

void dfs(int i, int f){
    vis[i] = 1;
    low[i] = d[i] = time++;
    
    for (int j = 0; j < graph[i].size(); j++){
        if (vis[graph[i][j]] == 0){
            dfs(graph[i][j], i);
            low[i] = min(low[i], low[graph[i][j]]);
            if (low[graph[i][j]] > d[i]) contp++; // found a bridge
        }
        else if (graph[i][j] != f) low[i] = min(low[i], d[graph[i][j]]);
    }
}
