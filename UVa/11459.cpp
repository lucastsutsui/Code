#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int test=0, a, b, c, from, to;
    int mat[106];
    int players[1000000];
    
    scanf ("%d", &test);
    
    while (test--){
        scanf ("%d %d %d", &a, &b, &c);
        
        for (int i = 0; i <= 100; i++) mat[i] = 0;
        for (int i = 0; i < a; i++) players[i] = 1;
        
        for (int i = 0; i < b; i++){
            scanf ("%d %d", &from, &to);
            mat[from] = to;
        }
        
        int k = 0, die;
        bool end = false;
        for (int i = 0; i < c; i++){
            scanf ("%d", &die);
            if (players[k] < 100 && !end){
                players[k] += die;
                if (players[k] > 100) players[k] = 100;
                if (mat[players[k]] > 0) players[k] = mat[players[k]];
                if (players[k] == 100) end = true;
                k = (k+1)%a;
            }
        }
        
        for (int i = 0; i < a; i++) printf ("Position of player %d is %d.\n", i+1, players[i]);
    }
    
    return 0;
}