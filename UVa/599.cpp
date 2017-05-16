#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t, contv, conte, cont;
    char b,e;
    bitset<26> adj, v;
    scanf ("%d", &t);
    getchar();
    
    while (t--){
        conte = contv = 0;
        adj.reset(); v.reset();
        
        while (getchar() != '*'){
            scanf("%c,%c)\n", &b, &e);
            adj[b-'A'] = 1;
            adj[e-'A'] = 1;
            conte++;
        }
        while (getchar() != '\n');
        b = getchar();
        while (b != '\n' && b != EOF){
            if (b != ','){
                contv++;
                v[b-'A'] = 1;
            }
            b = getchar();
        }
        cont = 0;
        for (int i = 0; i < 26; i++) if (!adj[i] && v[i]) cont++;
        printf ("There are %d tree(s) and %d acorn(s).\n", (contv-conte-cont), cont); //return 0;
    }
    
    return 0;
}