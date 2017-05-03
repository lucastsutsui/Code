#include <bits/stdc++.h>
using namespace std;

string s1,s2,ans;
stack<char> p;

void bc(int i, int k){
    if (k == s2.size()){
        cout << ans[0];
        for (int ia = 1; ia < ans.size(); ia++) cout << ' ' << ans[ia]; 
        cout << '\n';
        return;
    }
    
    if (i < s1.size()){
        p.push(s1[i]);
        ans += "i";
        bc(i+1,k);
        p.pop();
        ans.erase(ans.end()-1);
    }
    if (p.size() && p.top() == s2[k]){
        p.pop();
        ans += "o";
        bc(i,k+1);
        p.push(s2[k]);
        ans.erase(ans.end()-1);
    }
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> s1 >> s2){
        cout << "[\n";
        ans = "";
        while (p.size()) p.pop();
        bc(0, 0);
        cout << "]\n";
    }
    
    return 0;
}