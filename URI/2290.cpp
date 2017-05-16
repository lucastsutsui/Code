#include <bits/stdc++.h>
using namespace std;

int n, p;
long long v[100005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n && n){
	    for (int i = 0; i < n; i++) cin >> v[i];
	    sort(v,v+n); p = 0;
	    for (int i = 0; i < n && p < 2; i++){
	        if (i < n-1 && v[i] == v[i+1]) i++;
	        else  cout << v[i] << (p++ == 0 ? ' ' : '\n');
	    }
	}
	return 0;
}