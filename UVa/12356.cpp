#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int b, s, l, r;
	int vl[112345];
	int vr[112345];
	
	while (true){
	    cin >> s >> b;
	    if (b == 0 && s == 0) break;
	    for (int i = 1; i <= s; i++){
	        vl[i] = i-1;
	        vr[i] = i+1;
	    }
	    vl[1] = vr[s] = -1;
	    for (int i = 0; i < b; i++){
	        cin >> l >> r;
	        
	        if (vl[l] == -1) cout << '*';
	        else cout << vl[l];
	        
	        if (vr[r] == -1) cout << " *\n";
	        else cout << ' ' << vr[r] << '\n';
	        
	        vr[vl[l]] = vr[r];
	        vl[vr[r]] = vl[l];
	    }
	    cout << "-\n"; 
	}
	return 0;
}