#include <bits/stdc++.h>
using namespace std;

char up(char x){
    if (x == '0') return '1';
    return x;
}

int main ()
{
    string chess;
    char tab[8][8];
    
    while (getline(cin,chess)){
        for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) tab[i][j] = '0';

        int row = 0, col=0;
        for (int i = 0; i < chess.size(); i++){
            if (chess[i] == '/'){
                col = 0;
                row++;
                continue;
            }
            if (chess[i] <= '9' && chess[i] >= '1') col += (chess[i]-'0');
            else tab[row][col++] = chess[i];
        }
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (tab[i][j] == 'p' && i < 7){ // pawn
                    if (j > 0) tab[i+1][j-1] = up(tab[i+1][j-1]);
                    if (j < 7) tab[i+1][j+1] = up(tab[i+1][j+1]);
                }
                else if (tab[i][j] == 'P' && i > 0){
                    if (j > 0) tab[i-1][j-1] = up(tab[i-1][j-1]);
                    if (j < 7) tab[i-1][j+1] = up(tab[i-1][j+1]);
                }
                else if (tab[i][j] == 'n' || tab[i][j] == 'N'){ // knight
                    if (i > 1){
                        if (j > 0) tab[i-2][j-1] = up(tab[i-2][j-1]);
                        if (j < 7) tab[i-2][j+1] = up(tab[i-2][j+1]);
                    }
                    if (j > 1){
                        if (i > 0) tab[i-1][j-2] = up(tab[i-1][j-2]);
                        if (i < 7) tab[i+1][j-2] = up(tab[i+1][j-2]);
                    }
                    if (j < 6){
                        if (i > 0) tab[i-1][j+2] = up(tab[i-1][j+2]);
                        if (i < 7) tab[i+1][j+2] = up(tab[i+1][j+2]);
                    }
                    if (i < 6){
                        if (j > 0) tab[i+2][j-1] = up(tab[i+2][j-1]);
                        if (j < 7) tab[i+2][j+1] = up(tab[i+2][j+1]);
                    }
                }
                else if (tab[i][j] == 'b' || tab[i][j] == 'B'){ // bishop
                    int l = i+1, k = j+1; while (l < 8 && k < 8 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l++][k++] = '1';
                    l = i+1; k = j-1; while (l < 8 && k >= 0 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l++][k--] = '1';
                    l = i-1; k = j+1; while (l >= 0 && k < 8 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l--][k++] = '1';
                    l = i-1; k = j-1; while (l >= 0 && k >= 0 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l--][k--] = '1';
                }
                else if (tab[i][j] == 'r' || tab[i][j] == 'R'){ // rook
                    int k = i+1; while (k < 8 && (tab[k][j] == '0' || tab[k][j] == '1')) tab[k++][j] = '1';
                    k = i-1; while (k >= 0 && (tab[k][j] == '0' || tab[k][j] == '1')) tab[k--][j] = '1';
                    k = j+1; while (k < 8 && (tab[i][k] == '0' || tab[i][k] == '1')) tab[i][k++] = '1';
                    k = j-1; while (k >= 0 && (tab[i][k] == '0' || tab[i][k] == '1')) tab[i][k--] = '1';
                }
                else if (tab[i][j] == 'q' || tab[i][j] == 'Q'){ // queen
                    int k = i+1; while (k < 8 && (tab[k][j] == '0' || tab[k][j] == '1')) tab[k++][j] = '1';
                    k = i-1; while (k >= 0 && (tab[k][j] == '0' || tab[k][j] == '1')) tab[k--][j] = '1';
                    k = j+1; while (k < 8 && (tab[i][k] == '0' || tab[i][k] == '1')) tab[i][k++] = '1';
                    k = j-1; while (k >= 0 && (tab[i][k] == '0' || tab[i][k] == '1')) tab[i][k--] = '1';
                    
                    int l = i+1; k = j+1; while (l < 8 && k < 8 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l++][k++] = '1';
                    l = i+1; k = j-1; while (l < 8 && k >= 0 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l++][k--] = '1';
                    l = i-1; k = j+1; while (l >= 0 && k < 8 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l--][k++] = '1';
                    l = i-1; k = j-1; while (l >= 0 && k >= 0 && (tab[l][k] == '0' || tab[l][k] == '1')) tab[l--][k--] = '1';
                }
                else if (tab[i][j] == 'k' || tab[i][j] == 'K'){ // king
                    if (j > 0 && i > 0) tab[i-1][j-1] = up(tab[i-1][j-1]);
                    if (j > 0 && i < 7) tab[i+1][j-1] = up(tab[i+1][j-1]);
                    if (j < 7 && i > 0) tab[i-1][j+1] = up(tab[i-1][j+1]);
                    if (j < 7 && i < 7) tab[i+1][j+1] = up(tab[i+1][j+1]);
                    if (i > 0) tab[i-1][j] = up(tab[i-1][j]);
                    if (i < 7) tab[i+1][j] = up(tab[i+1][j]);
                    if (j > 0) tab[i][j-1] = up(tab[i][j-1]);
                    if (j < 7) tab[i][j+1] = up(tab[i][j+1]);
                }
            }
        }
        int cont = 0;
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) if (tab[i][j] == '0') cont++;

        cout << cont << endl;
    }
    
    return 0;
}