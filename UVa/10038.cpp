#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, ans, num;
	bitset<3123> v;
	
	while (cin >> n && n){
	    v.reset();
	    bool flag = true;
	    for (int i = 0; i < n; i++){ 
	        cin >> num;
	        if (i != 0){
	            if (abs(num-ans) >= n) flag = false;
	            else v[abs(num-ans)] = 1;
	        }
	        ans = num;
	    }
	    for (int i = 1; i < n; i++) if (!v[i]) flag = false;
	    if (flag) cout << "Jolly\n";
	    else cout << "Not jolly\n";
	}
	return 0;
}