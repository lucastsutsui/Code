#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    bitset<212345> v;
    
    cin >> n;
    
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i < n; i++){
        if (v[i-2] == 0 && v[i-1] == 0) v[i] = 1;
        else if (v[i-2] == 0 && v[i-1] == 1) v[i] = 1;
        else if (v[i-2] == 1 && v[i-1] == 0) v[i] = 0;
        else v[i] = 0;
    }
    
    for (int i = 0; i < n; i++) cout << (char)('a'+(int)v[i]);
    cout << '\n';
    
    return 0;
}