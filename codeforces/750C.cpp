#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, ci, di, mx=INT_MIN, mn=INT_MAX, sum=0;
    scanf("%d", &n);    
    for (int i = 0; i < n; i++){
        scanf("%d%d", &ci, &di);
        if (di == 1) mx = max(mx,1900-sum);
        else mn = min(mn,1899-sum);
        sum += ci;
    }    
    if (mn < mx) printf("Impossible");
    else if (mn == INT_MAX) printf("Infinity");
    else printf("%d", mn+sum);    
    return 0;
}
