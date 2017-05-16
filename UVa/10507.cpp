#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m, cont[50], years;
    bool slp[50], ok;
    vector<int> graph[50];
    string str;
    
    while (cin >> n){
        for (int i = 0; i < 26; i++) slp[i] = true, graph[i].clear();
        years = 0;
        cin >> m;
        cin >> str;
        slp[str[0]-'A'] = slp[str[1]-'A'] = slp[str[2]-'A'] = false;
        for (int i = 0; i < m; i++){
            cin >> str;
            graph[str[0]-'A'].push_back(str[1]-'A');
            graph[str[1]-'A'].push_back(str[0]-'A');
        }
        ok = true; n -= 3;
        while (n > 0){
            for (int i = 0; i < 26; i++) cont[i] = 0;
            for (int i = 0; i < 26; i++)
                if (!slp[i])
                    for (int j = 0; j < graph[i].size(); j++) if (slp[graph[i][j]]) cont[graph[i][j]]++;
            ok = false;
            for (int i = 0; i < 26; i++)
                if (cont[i] >= 3) slp[i] = false, ok = true, n--;
            if (!ok) break;
            years++;
        }
        
        if (ok) cout << "WAKE UP IN, " << years << ", YEARS\n";
        else cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    
    return 0;
}
