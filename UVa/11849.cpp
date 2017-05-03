#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, cont, num;
    set<int> v;
    
    while (true){
        cin >> n >> m;
        if (!n && !m) break;
        
        v.clear();
        cont = 0;
        
        for (int i = 0; i < n; i++){
            cin >> num;
            v.insert(num);
        }
        for (int i = 0; i < m; i++){
            cin >> num;
            if (v.find(num) != v.end()) cont++;
        }
        
        cout << cont << '\n';
    }
    
    return 0;
}