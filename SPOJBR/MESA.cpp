#include <stdio.h>

int n,m;
int mark[123];
int graph[123][123];
int adj[123];

int dfs(int i, char color){
    if (mark[i] != -1) return (mark[i] == color);
    
    mark[i] = color;
    color = (color+1)%2;
    
    for (int j = 0; j < adj[i]; j++) 
        if (!dfs(graph[i][j], color)) return 0;
        
    return 1;
}

int main() 
{
	int u,v,inst=1;
	
	while (scanf("%d %d", &n, &m) != EOF){
	    for (int i = 0; i < n; i++){ adj[i] = 0; mark[i] = -1; }
	    
	    for (int i = 0; i < m; i++){
	        scanf("%d %d", &u, &v); u--; v--;
	        graph[u][adj[u]++] = v;
	        graph[v][adj[v]++] = u;
	    }
	   
	    int answer = 1;
	    for (int i = 0; i < n; i++) if (mark[i] == -1 && !dfs(i, 0)) answer = 0;
	    
	    printf ("Instancia %d\n%s\n\n", inst++, (answer == 1 ? "sim" : "nao"));
	}
	
    return 0;
}
