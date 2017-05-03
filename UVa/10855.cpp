#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int N,n;
char m1[1123][1123];
char m2[1123][1123];
char aux[1123][1123];

void rot(){
    rep(i,n) rep(j,n) aux[j][n-i-1] = m2[i][j];
    rep(i,n) rep(j,n) m2[i][j] = aux[i][j];
}

int find(){
    int cont = 0;
    
    rep(i,N-n+1) rep(j,N-n+1){
        bool flag = true;
        rep(k,n){
            rep(l,n) if (m1[i+k][j+l] != m2[k][l]) flag = false;
            if (!flag) break;
        }
        if (flag) cont++;
    }
    
    return cont;
}

int main() 
{
    while (true){
        scanf("%d %d", &N, &n);
        if (N == 0 && n == 0) break;
        rep(i,N) scanf("%s", m1[i]);
        rep(i,n) scanf("%s", m2[i]);
        
        printf("%d ", find());
        rot();
        printf("%d ", find());
        rot();
        printf("%d ", find());
        rot();
        printf("%d\n", find());
    }
    return 0;
}