#include <bits/stdc++.h>
using namespace std;

int p[112345];
int r[112345];

int find(int a){
    return (p[a] == a) ? a : (p[a] = find(p[a]));
}

void unite(int a, int b){
    int x = find(a), y = find(b);
    if (x == y) return;
    if (r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
    }
}

int main() 
{
    int t, n, a, b, suc, uns;
    char c;
    
    scanf ("%d", &t);
    
    while (t--){
        suc = uns = 0;
        scanf ("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) p[i] = i, r[i] = 0;
        
        c = getchar();
        while (c != '\n' && c != EOF){
            scanf("%d %d", &a, &b); getchar();
            if (c == 'c') unite(a-1,b-1);
            else{
                if (find(a-1) == find(b-1)) suc++;
                else uns++;
            }
            c = getchar();
        }
        printf ("%d,%d\n", suc, uns);
        if (t) puts("");
    }
    
    return 0;
}