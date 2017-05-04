#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

class cmp{
    public: bool operator ()(ii &p1, ii &p2){ 
        if (p1.second == p2.second) return p1.first > p2.first;
        return p1.second > p2.second; 
    }
};

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    priority_queue<ii, vii, cmp> pq;
    map<int,int> v;
    string str;
    int n1, n2, k, cont;
    
    while (cin >> str){
        if (str == "#") break;
        cin >> n1 >> n2;
        pq.push(ii(n1,n2));
        v[n1] = n2;
    }
    
    cin >> k;
    
    for (int i = 0; i < k; i++){
        n1 = pq.top().first;
        n2 = pq.top().second;
        pq.pop();
        pq.push(ii(n1,n2+v[n1]));
        cout << n1 << '\n';
    }
    
    return 0;
}