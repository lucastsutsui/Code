#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

pair<int,int> calc(int n, lld p){
    int k = (int)((sqrt(1+4*p)-1)/2.0);
    int x = n/2+1, y = n/2+1;
    if (p == 0) return make_pair(x,y);
    while (k*1ll*(k+1) > p) k--;
    if (k%2 == 1){
        x -= k/2+1; y += k/2+1;
        if (k*1ll*(k+1) == p) p = p;
        else if (p <= k*1ll*(k+1)+k+1) y -= (p-(k*1ll*(k+1)));
        else{ y -= k+1; x += (p-(k*1ll*(k+1))-k-1); }
    }
    else{
        x += k/2; y -= k/2;
        if (k*1ll*(k+1) == p) p = p;
        else if (p <= k*1ll*(k+1)+k+1) y += (p-(k*1ll*(k+1)));
        else{ y += k+1; x -= (p-(k*1ll*(k+1))-k-1); }
    }
    return make_pair(x,y);
}

int main() 
{
    int sz;
    lld p;
    pair<int,int> ans;
    
    while (true){
        scanf("%d %lld", &sz, &p);
        if (sz == 0 && p == 0) break;
        ans = calc(sz,p-1);
        printf("Line = %d, column = %d.\n", ans.second, ans.first);
    }
    return 0;
}