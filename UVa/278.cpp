#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t,n,m;
    char op;
    
    scanf("%d", &t);
    
    while (t--){
        getchar();
        scanf("%c %d %d", &op, &m, &n);
        if (op == 'Q' || op == 'r') cout << min(n,m) << endl;
        else if (op == 'K') cout << ((m+1)/2)*((n+1)/2) << endl;
        else cout << (n*m+1)/2 << endl;
    }
    
    return 0;
}