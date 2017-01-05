#include <bits/stdc++.h>
using namespace std;

int t,r,c,n;
char curr[101][101], nextg[101][101];

bool test(int i, int j, char a, char b){
    if (curr[i][j] == a && ((i > 0 && curr[i-1][j] == b) || (i < r-1 && curr[i+1][j] == b) || 
    (j > 0 && curr[i][j-1] == b) || (j < c-1 && curr[i][j+1] == b)))
        return true;
    return false;
}

int main() {
    scanf("%d", &t);
    
    while (t--){
        scanf ("%d %d %d", &r, &c, &n);
        getchar();
        for (int i = 0; i < r; i++) scanf("%s", curr[i]);
        
        for (int k = 0; k < n; k++){
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    if (test(i,j,'R','P')) nextg[i][j] = 'P';    
                    else if (test(i,j,'S','R')) nextg[i][j] = 'R';
                    else if (test(i,j,'P','S')) nextg[i][j] = 'S';
                    else nextg[i][j] = curr[i][j];
                }
            }
            swap(nextg, curr);
        }
        
        for (int i = 0; i < r; i++) printf("%s\n", curr[i]);
        if (t) printf("\n");
    }
    
	return 0;
}