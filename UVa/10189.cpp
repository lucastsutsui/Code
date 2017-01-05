#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m,cases=0;
    int mat[101][101];
    char op;
    
    while (scanf("%d %d", &n, &m) && (n||m)){
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) mat[i][j] = 0;
        for (int i = 0; i < n; i++){
            getchar();
            for (int j = 0; j < m; j++){
                op = getchar();       
                if (op == '*'){
                    mat[i][j] = -1;
                    if (i > 0){
                        if (mat[i-1][j] != -1) mat[i-1][j]++;
                        if (j > 0 && mat[i-1][j-1] != -1) mat[i-1][j-1]++;
                        if (j < m-1 && mat[i-1][j+1] != -1) mat[i-1][j+1]++;
                    }
                    if (i < n-1){
                        if (mat[i+1][j] != -1) mat[i+1][j]++;
                        if (j > 0 && mat[i+1][j-1] != -1) mat[i+1][j-1]++;
                        if (j < m-1 && mat[i+1][j+1] != -1) mat[i+1][j+1]++;
                    }
                    if (j > 0 && mat[i][j-1] != -1) mat[i][j-1]++;
                    if (j < m-1 && mat[i][j+1] != -1) mat[i][j+1]++;
                }
            }
        }
        if (cases > 0) printf("\n");
        printf ("Field #%d:\n", ++cases);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == -1) printf("%c", '*');
                else printf("%d", mat[i][j]);
            }  
            printf ("\n");
        } 
    }
    
    return 0;
}