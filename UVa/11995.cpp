#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    int n, t, x;
    bool st, qu, pqu;
    
    while (cin >> n){
        st = qu = pqu = true;
        while (s.size()) s.pop();
        while (q.size()) q.pop();
        while (pq.size()) pq.pop();
        
        for (int i = 0; i < n; i++){
            cin >> t >> x;
            if (t == 1){
                if (st) s.push(x);
                if (qu) q.push(x);
                if (pqu) pq.push(x);
            }
            else{
                if (st && s.size() && s.top() == x) s.pop();
                else st = false;
                
                if (qu && q.size() && q.front() == x) q.pop();
                else qu = false;
                
                if (pqu && pq.size() && pq.top() == x) pq.pop();
                else pqu = false;
            }
        }
        
        if (!st && !qu && !pqu) cout << "impossible\n";
        else if (st && !qu && !pqu) cout << "stack\n";
        else if (!st && qu && !pqu) cout << "queue\n";
        else if (!st && !qu && pqu) cout << "priority queue\n";
        else cout << "not sure\n";
    }
    
    return 0;
}