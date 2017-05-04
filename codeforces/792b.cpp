#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, a[123];
    vector<int> v;
    
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < n; i++) v.push_back(i+1);
    
    int curr = 0, kill;
    for (int i = 0; i < k; i++){
        kill = (a[i]+curr)%v.size();
        cout << v[kill] << ' ';
        v.erase(v.begin()+kill);
        curr = kill%v.size();
    }
    
	return 0;
}
