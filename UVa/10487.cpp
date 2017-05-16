#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, v[1123], test=1;
    
    while (cin >> n && n){
        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> m;
        cout << "Case " << test++ << ":\n";
        for (int i = 0; i < m; i++){
            int num; cin >> num;
            int sum = INT_MIN;
            for (int j = 0; j < n-1; j++)
                for (int k = j+1; k < n; k++)
                    if (sum == INT_MAX || abs(v[k]+v[j]-num) < abs(sum-num)) sum = v[k]+v[j];
            cout << "Closest sum to " << num << " is " << sum << ".\n";
        }
    }
    
	return 0;
}
