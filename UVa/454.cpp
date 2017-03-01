#include <bits/stdc++.h>
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main() 
{
	int t;
	string str;
	vector<string> dic, w;
	bool prim=true;
	
	cin >> t;
	getchar(); getchar();
	
	while (t--){ 
	    dic.clear();
	    while (true){
	        getline(cin, str);
	        if (str.size() == 0) break;
	        dic.push_back(str);
	    }
	    sort(dic.begin(), dic.end());
	    w.assign(dic.begin(), dic.end());
	    forn(i,w.size()){
	        sort(w[i].begin(), w[i].end()); 
	        forn(j,w[i].size()) if (w[i][j] == ' '){ w[i].erase(w[i].begin()+j); j--; }
	    }
	    //forn(i,w.size()) cout << w[i] << endl;
	    if (!prim) cout << endl;
	    forn(i,w.size())
	        for (int j = i+1; j < w.size(); j++)
	            if (w[i] == w[j]) cout << dic[i] << " = " << dic[j] << endl;
        prim = false;
	}
    
	return 0;
}