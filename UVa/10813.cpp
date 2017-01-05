#include <bits/stdc++.h>
using namespace std;

int tab[5][5];

bool check(){
    for (int i = 0; i < 5; i++) if (tab[i][0] == -1 && tab[i][1] == -1 && tab[i][2] == -1 && tab[i][3] == -1 && tab[i][4] == -1) return true;
    for (int j = 0; j < 5; j++) if (tab[0][j] == -1 && tab[1][j] == -1 && tab[2][j] == -1 && tab[3][j] == -1 && tab[4][j] == -1) return true;
    if (tab[0][0] == -1 && tab[1][1] == -1 && tab[2][2] == -1 && tab[3][3] == -1 && tab[4][4] == -1) return true;
    if (tab[0][4] == -1 && tab[1][3] == -1 && tab[2][2] == -1 && tab[3][1] == -1 && tab[4][0] == -1) return true;
    return false;
}

int main() {
    int n, num[75]; 
    
    scanf("%d", &n);
    
    while (n--){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (i != 2 || j != 2) scanf("%d", &tab[i][j]);
                else tab[i][j] = -1;
            }
        }
        
        for (int i = 0; i < 75; i++) scanf("%d", &num[i]);
        
        int rounds = 0;
        while (rounds < 75){
            for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (tab[i][j] == num[rounds]) tab[i][j] = -1;
            if (check()) break;
            rounds++;
        }
        
        printf ("BINGO after %d numbers announced\n", rounds+1);
    }
    
	return 0;
}
