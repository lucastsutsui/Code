#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef pair<int,int> ii;

int dist(ii a, ii b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int m, ans;
    string tab[105];
    vector<ii> one, three;
    
    while (cin >> m){
        one.clear(); three.clear();
        
        for (int i = 0; i < m; i++) cin >> tab[i];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                if (tab[i][j] == '1') one.pb(ii(i,j));
                else if (tab[i][j] == '3') three.pb(ii(i,j));
            }
        }
        ans = INT_MIN;
        for (int i = 0; i < one.size(); i++){
            int d = INT_MAX;
            for (int j = 0; j < three.size(); j++) d = min(d, dist(one[i], three[j]));
            ans = max(ans,d);
        }
        cout << ans << '\n';
    }
    
	return 0;
}
