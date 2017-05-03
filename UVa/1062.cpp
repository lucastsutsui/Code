#include <bits/stdc++.h>
using namespace std;

string str;

int solve(){
    string p;
    
    p += str[0];
    
    for (int i = 1; i < str.size(); i++){
        bool flag = true;
        for (int j = 0; j < p.size(); j++) if (str[i] <= p[j]){ p[j] = str[i]; flag = false; break; }
        if (flag) p += str[i];
    }
    
    return p.size();
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test=1;
    
    while (true){
        cin >> str;
        if (str == "end") break;
        cout << "Case " << test++ << ": " << solve() << '\n';
    }
    
    return 0;
}