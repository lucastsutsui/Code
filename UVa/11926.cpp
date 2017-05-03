#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, s, e, it;
    bitset<MAX+1> v;
    bool flag;
    
    while (true){
        v.reset();
        flag = true;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++){
            cin >> s >> e;
            for (int j = s; flag && j < e; j++){
                if (v[j] == 1){ flag = false; break; }
                v[j] = 1;
            }
        }
        for (int i = 0; i < m; i++){
            cin >> s >> e >> it;
            while (flag && s < MAX){
                for (int j = s; j < MAX && j < e; j++){
                    if (v[j] == 1){ flag = false; break; }
                    v[j] = 1;
                }
                s += it;
                e += it;
            }
        }
        if (flag) cout << "NO CONFLICT\n";
        else cout << "CONFLICT\n";
    }
    return 0;
}