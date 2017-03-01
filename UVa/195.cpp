#include <bits/stdc++.h>
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

bool cmp (string a, string b){
    forn(i,a.size()){
        if (toupper(a[i]) != toupper(b[i])) return toupper(a[i]) < toupper(b[i]);
        else if (a[i] != b[i]) return a[i] < b[i];
    }
    return a < b;
}

int main() 
{
	int t;
	string str;
	vector<string> ans;
	
	cin >> t;
	
	while (t--){ ans.clear();
	    cin >> str;
	    sort(str.begin(), str.end());
	    do{ 
	        ans.push_back(str);
	    } while (next_permutation(str.begin(), str.end()));
	    sort(ans.begin(), ans.end(), cmp);
	    forn(i,ans.size()) cout << ans[i] << endl;
	}
    
	return 0;
}