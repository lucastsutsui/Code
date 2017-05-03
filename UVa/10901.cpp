#include <bits/stdc++.h>
#define el '\n'
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;

int n, t, m;
int tt[10123];
queue<ii> lf, rg;

int mn(){
    if (lf.size() && rg.size()) return min(lf.front().F,rg.front().F);
    if (lf.size()) return lf.front().F;
    return rg.front().F;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int c, min, curr, kk;
    bool l;
    string dir;
    cin >> c;
    while (c--){
        cin >> n >> t >> m;
        for (int i = 0; i < m; i++){
            cin >> min >> dir;
            if (dir == "left") lf.push(ii(min,i));
            else rg.push(ii(min,i));
        }
        l = true;
        curr = 0;
        while (lf.size() || rg.size()){
            curr = max(curr, mn());
            
            int kk = 0;
            while (l && lf.size() && kk < n && lf.front().F <= curr){
                tt[lf.front().S] = curr+t;
                lf.pop(); kk++;
            }
            while (!l && rg.size() && kk < n && rg.front().F <= curr){
                tt[rg.front().S] = curr+t;
                rg.pop(); kk++;
            }
            
            curr += t;
            l = !l;
        }
        for (int i = 0; i < m; i++) cout << tt[i] << el;
        if (c != 0) cout << el;
    }
    
    return 0;
}