#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int m, n, r, num;
    int nz[1123];
    vector<int> v[11234], pos[11234];
    
    while (cin >> m >> n){
        for (int i = 0; i < n; i++) v[i].clear(), pos[i].clear();
        
        for (int i = 0; i < m; i++){
            cin >> r;
            for (int j = 0; j < r; j++) cin >> nz[j];
            for (int j = 0; j < r; j++){
                cin >> num;
                v[nz[j]-1].push_back(num);
                pos[nz[j]-1].push_back(i+1);
            }
        }
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < n; i++){
            cout << pos[i].size();
            for (int j = 0; j < pos[i].size(); j++) cout << ' ' << pos[i][j];
            cout << '\n';
            for (int j = 0; j < v[i].size(); j++){ 
                if (j) cout << ' ';
                cout << v[i][j]; 
            }
            cout << '\n';
        }
    }
    
    return 0;
}