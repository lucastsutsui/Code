#include <bits/stdc++.h>
using namespace std;

int n;
int v[1123];

bool test(){
    stack<int> p;
    int k = 0;
    
    for (int i = 1; i <= n; i++){
        if (v[k] == i) k++;
        else p.push(i);
        
        while (p.size() && p.top() == v[k]){ p.pop(); k++; }
    }
    
    return (k == n && p.size() == 0);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (true){
        cin >> n;
        if (n == 0) break;
        while (true){
            for (int i = 0; i < n; i++){
                cin >> v[i];
                if (i == 0 && v[i] == 0) break;
            }
            if (v[0] == 0) break;
            if (test()) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << '\n';
    }
    
    return 0;
}