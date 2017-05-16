#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t, n, v[1123], total;
    
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; i++) cin >> v[i];
        total = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) if (v[j] <= v[i]) total++;
        cout << total << '\n';
    }
    
	return 0;
}
