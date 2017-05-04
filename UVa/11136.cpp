#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, num, k;
    long long cont;
    multiset<int> v;
    multiset<int>::iterator it;
    
    while (true){
        cin >> n;
        if (!n) break;
        
        v.clear();
        cont = 0;
        
        for (int i = 0; i < n; i++){
            cin >> k;
            for (int j = 0; j < k; j++){
                cin >> num; v.insert(num);
            }
            it = v.begin();
            cont -= *(it);
            v.erase(it);
            it = v.end(); it--;
            cont += *(it);
            v.erase(it);
        }
        
        cout << cont << '\n';
    }
    
    return 0;
}
