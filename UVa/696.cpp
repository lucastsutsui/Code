#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m;
    
    while (scanf("%d %d", &n, &m) && (n || m)){
        if (n*m == 0) cout << 0;
        else if (n==1 || m==1) cout << max(n,m);
        else if (n==2 || m==2) cout << max(n,m)+((max(n,m)%4)==3 ? 1 : (max(n,m)%4));
        else cout << (n*m+1)/2;
        cout << " knights may be placed on a " << n << " row " << m << " column board.\n";
    }
    
    return 0;
}