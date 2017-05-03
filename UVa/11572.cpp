#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int c, n, num, cont, mx;
    set<int> elems;
    queue<int> q;
    
    cin >> c;
    while (c--){
        cin >> n;
        elems.clear();
        while (q.size()) q.pop();
        cont = mx = 0;
        
        for (int i = 0; i < n; i++){
            cin >> num;
            
            if (elems.find(num) != elems.end()){
                while (q.size() && q.front() != num){
                    elems.erase(q.front());
                    q.pop();
                    cont--;
                }
                if (q.size()){
                    elems.erase(num); q.pop(); cont--;
                }
            }
            
            elems.insert(num);
            q.push(num);
            cont++;
            
            mx = max(mx,cont);
        }
        
        cout << mx << el;
    }
    
    return 0;
}