#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, mx;
    int v[33000], pot[33000];
    
    while (cin >> n){
        for (int i = 0; i < (1 << n); i++){ 
            cin >> v[i]; 
            pot[i] = 0; 
        }
        for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) pot[i^(1 << j)] += v[i];
        mx = 0;
        for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) mx = max(mx, pot[i]+pot[i^(1 << j)]);
        cout << mx << el;
    }
    return 0;
}