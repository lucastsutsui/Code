#include <bits/stdc++.h>
using namespace std;
#define pb push_back

typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m;
vector<vii> graph(1008);
int dist[1008];
bool visited[1008];

class prioritize{
    public: bool operator ()(ii &p1, ii &p2){ return p1.second > p2.second; }
};

void dijkstra(){
    for (int i = 0; i <= n+1; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    priority_queue<ii ,vii, prioritize> pq; 
    dist[0] = 0;
    pq.push(ii(0,0)); 
    while(!pq.empty()){
        ii curr = pq.top(); 
        pq.pop();
        int cv=curr.first,cw=curr.second;
        if(visited[cv]) continue;
        visited[cv] = true; 
        
        for(int i = 0; i < graph[cv].size(); i++)
            if(!visited[graph[cv][i].first] && graph[cv][i].second + cw < dist[graph[cv][i].first])
                pq.push(ii(graph[cv][i].first,(dist[graph[cv][i].first] = graph[cv][i].second+cw)));
    }
}

int main() 
{
    int s,t,b;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &s, &t, &b);
        graph[s].pb(ii(t,b));
        graph[t].pb(ii(s,b));
    }
    
    dijkstra();
    
    printf ("%d\n", dist[n+1]);
    
    return 0;
}
