#include <bits/stdc++.h>
using namespace std;

typedef struct{
    string car;
    int l, h;
} Record;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t, d, q, p;
    Record v[11234];
    
    cin >> t;
    while (t--){
        cin >> d;
        for (int i = 0; i < d; i++) cin >> v[i].car >> v[i].l >> v[i].h;
        cin >> q;
        while (q--){
            cin >> p;
            int ind = -1;
            for (int i = 0; i < d; i++) if (p <= v[i].h && p >= v[i].l) ind = (ind >= 0 ? INT_MAX : i);
            if (ind == INT_MAX || ind == -1) cout << "UNDETERMINED\n";
            else cout << v[ind].car << '\n';
        }
        if (t) cout << '\n';
    }
    
	return 0;
}
