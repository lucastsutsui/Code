#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, v[212345];
    
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> v[i];
    
    sort(v,v+n);
    
    int cont = 0, mn = INT_MAX;
    
    for (int i = 1; i < n; i++) mn = min(abs(v[i]-v[i-1]), mn);
    for (int i = 1; i < n; i++) if (abs(v[i]-v[i-1]) == mn) cont++;
    
    cout << mn << ' ' << cont;
    
    return 0;
}
