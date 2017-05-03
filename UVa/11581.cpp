#include <bits/stdc++.h>
#define rep(i,b,n) for(int (i)=b;(i)<(n);(i)++)
using namespace std;

char g[5][5];
char f[5][5];

bool cmp(){
    rep(i,1,4) rep(j,1,4) if (g[i][j] == 1) return false;
    return true;
}

int main() 
{
    int n;
    scanf("%d", &n);
    while (n--){
        getchar();
        
        rep(i,1,4){ 
            getchar();
            rep(j,1,4) g[i][j] = getchar()-'0';
        }
        
        rep(i,0,5) g[0][i] = g[4][i] = g[i][0] = g[i][4] = 0;
        
        int cont = -1;
        while(true){
            if (cmp()) break;
            rep(i,1,4) rep(j,1,4) f[i][j] = (g[i-1][j]+g[i+1][j]+g[i][j-1]+g[i][j+1])%2;
            rep(i,1,4) rep(j,1,4) g[i][j] = f[i][j];
            cont++;
        }
        
        printf("%d\n", cont);
    }
	return 0;
}