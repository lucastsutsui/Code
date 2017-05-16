#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int k, x;
    vector<pair<int,int> > ans;
    
    while (cin >> k){
        ans.clear();
        for (int y = k+1; y <= 2*k; y++){
            x = (k*y)/(y-k);
            if (k*(y+x) == (y*x)) ans.push_back(make_pair(y,x));
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) 
            cout << "1/" << k << " = 1/" << ans[i].second << " + 1/" << ans[i].first << "\n";
    }
    
	return 0;
}