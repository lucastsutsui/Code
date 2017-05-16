#include <bits/stdc++.h>
using namespace std;

map<string,string> p;
map<string,int> r, qt;

string find(string a){
    return (p[a] == a) ? a : (p[a] = find(p[a]));
}

void unite(string a, string b){
    string x = find(a), y = find(b);
    if (x == y) return;
    if (r[x] > r[y]) p[y] = x, qt[x] += qt[y];
    else{
        p[x] = y;
        qt[y] += qt[x];
        if (r[x] == r[y]) r[y]++;
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t, n;
    string str1, str2;
    
    cin >> t;
    
    while (t--){
        p.clear(); qt.clear(); r.clear();
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> str1 >> str2;
            if (p.find(str1) == p.end()) p[str1] = str1, r[str1] = 0, qt[str1] = 1;
            if (p.find(str2) == p.end()) p[str2] = str2, r[str2] = 0, qt[str2] = 1;
            unite(str1, str2);
            cout << qt[find(str1)] << '\n';
        }
    }
    
    return 0;
}
