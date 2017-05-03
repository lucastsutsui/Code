#include <bits/stdc++.h>
using namespace std;

bool ok;

void dif(long long int a, long long int b){
    if (a==0 || b==0) return;
    dif(a/10,b/10);
    if (ok && a%10 != b%10){ 
        cout << "-"; 
        ok = false;
    }
    if (!ok) cout << b%10;
}

int main() 
{
	int n, test=1;
	long long int num, v[112345], ans;
	
	while (true){
	    cin >> n;
	    if (n==0) break;
	    cout << "Case " << test++ << ":\n";
	    for (int i = 0; i < n; i++){
	        cin >> num;
	        v[i] = num;
	    }
	    for (int i = 0; i < n; i++){
	        cout << "0" << v[i];
	        ans = v[i];
	        while (i+1 < n && v[i]+1 == v[i+1]) i++;
	        ok = true;
	        if (ans != v[i]) dif(ans,v[i]);
	        cout << "\n";
	    }
	    cout << "\n";
	}
	
	return 0;
}