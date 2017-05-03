#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, num, mx;
    map<vector<int>,int> f;
    map<vector<int>,int>::iterator it;
    
    while (cin >> n && n){
        mx = 0;
        f.clear();
        for (int i = 0; i < n; i++){
            vector<int> v;
            for (int j = 0; j < 5; j++){
                cin >> num;
                v.push_back(num);
            }
            sort(v.begin(),v.end());
            f[v]++;
            mx = max(mx,f[v]);
        }
        
        int cont = 0;
        for (it = f.begin(); it != f.end(); it++) if (it->second == mx) cont++;
        
        cout << cont*mx << el;
    }
    
    return 0;
}