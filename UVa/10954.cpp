#include <bits/stdc++.h>
using namespace std;

class cmp{
    public: bool operator ()(int &p1, int &p2){ return p1 > p2; }
};

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, num, cost;
    priority_queue<int, vector<int>, cmp> pq;
    
    while (true){
        cin >> n;
        if (!n) break;
        
        while (pq.size()) pq.pop();
        
        for (int i = 0; i < n; i++) {
            cin >> num;
            pq.push(num);
        }
        
        cost = 0;
        while (pq.size() > 1){
            int a = pq.top();
            pq.pop();
            cost += a + pq.top();
            pq.push(a+pq.top());
            pq.pop();
        }
        
        cout << cost << '\n';
    }
    
    return 0;
}