#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int c, cont;
    string sp;
    map<string,int> tree;
    vector<string> ans;
    
    cin >> c;
    getline(cin,sp); getline(cin,sp);
    while (c--){
        cont = 0;
        ans.clear();
        tree.clear();
        while (getline(cin,sp)){
            if (sp == "\n" || sp == "") break;
            if (tree.find(sp) != tree.end()) tree[sp]++;
            else{ 
                tree[sp] = 1; 
                ans.push_back(sp);
            }
            cont++;
        }    
        sort(ans.begin(), ans.end());
        cout << fixed << setprecision(4);
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << ' ' << 100.0*tree[ans[i]]/(double)cont << el;
        }
        if (c) cout << el;
    }
    
    return 0;
}