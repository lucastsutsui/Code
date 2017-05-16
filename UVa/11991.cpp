#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, num, k;
    
    while (cin >> n >> m){
        vector<int> v[1123123];
        
        for (int i = 0; i < n; i++){
            cin >> num;
            v[num].push_back(i+1);
        }
        for (int i = 0; i < m; i++){
            cin >> k >> num;
            if (v[num].size() < k) cout << "0\n";
            else cout << v[num][k-1] << '\n';
        }
    }
    
    return 0;
}
