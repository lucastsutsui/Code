#include <bits/stdc++.h>
#define el '\n'
#define forn(i,pp) for(int (i)=0;(i)<(pp);(i)++)
using namespace std;

int n, m;
long long ed, ve;
vector<vector<int> > grap(150001);
bool vis[150001];

void dfs(int curr){
    vis[curr] = true;
    ve++; ed += grap[curr].size();
    for (int i = 0; i < grap[curr].size(); i++) if (!vis[grap[curr][i]]) dfs(grap[curr][i]);
}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a,b;
	bool flag = true;
	
	cin >> n >> m;
	
	forn(i,m){
	    cin >> a >> b;
	    grap[a-1].push_back(b-1);
	    grap[b-1].push_back(a-1);
	}
	
	forn(i,n) vis[i] = false;
	
	forn(i,n){
	    if (vis[i] || grap[i].size() == 0) continue;
	    ed = ve = 0;
	    dfs(i);
	    if (ed != ve*1ll*(ve-1)) flag = false;
	}
	
	if (flag) cout << "YES\n";
	else cout << "NO\n";
	
    return 0;
}