#include <bits/stdc++.h>
#define E 0
#define N 1
#define W 2
#define S 3
using namespace std;

int n,m;
int tab[100][100];

void dfs(int i, int j, char dir){
    if (i == n && j == 1 && dir != E) return;
    
    if (dir == E){
        if (tab[i+1][j] != -1) dfs(i+1,j,S);
        else if (tab[i][j+1] != -1) dfs(i,j+1,E);
        else if (tab[i-1][j] != -1) dfs(i-1,j,N);
        else dfs(i,j-1,W);
    }
    else if (dir == N){
        if (tab[i][j+1] != -1) dfs(i,j+1,E);
        else if (tab[i-1][j] != -1) dfs(i-1,j,N);
        else if (tab[i][j-1] != -1) dfs(i,j-1,W);
        else dfs(i+1,j,S);
    }
    else if (dir == W){
        if (tab[i-1][j] != -1) dfs(i-1,j,N);
        else if (tab[i][j-1] != -1) dfs(i,j-1,W);
        else if (tab[i+1][j] != -1) dfs(i+1,j,S);
        else dfs(i,j+1,E);
    }
    else{
        if (tab[i][j-1] != -1) dfs(i,j-1,W);
        else if (tab[i+1][j] != -1) dfs(i+1,j,S);
        else if (tab[i][j+1] != -1) dfs(i,j+1,E);
        else dfs(i-1,j,N);
    }
    
    tab[i][j]++;
}

int main() 
{
    int cont[5];
    while (true){ 
        scanf ("%d %d", &n, &m);
        if (n==0 && m==0) break;
        for (int i = 0; i <= n+1; i++) tab[i][0] = tab[i][m+1] = 1;
        for (int i = 0; i <= m+1; i++) tab[0][i] = tab[n+1][i] = 1;
        
        for (int i = 1; i <= n; i++){
            getchar();
            for (int j = 1; j <= m; j++) tab[i][j] = getchar()-'0';
        }
        
        for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++) if (tab[i][j] == 1) tab[i][j] = -1;
        
        dfs(n,1,E);
        
        for (int i = 0; i < 5; i++) cont[i] = 0;
        for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++) 
            if (tab[i][j] != -1) cont[tab[i][j]]++;
        for (int i = 0; i < 5; i++) printf("%3d", cont[i]);
        printf("\n");
    }
	return 0;
}