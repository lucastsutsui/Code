/*
Returns minimum distance from source to destination
*/

vector<vii> graph(MAX);
int dist[MAX];
bool visited[MAX];

class prioritize{
    public: bool operator ()(ii &p1, ii &p2){ return p1.second > p2.second; }
};

int dijkstra(int source, int destination){

    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    priority_queue<ii ,vii, prioritize> pq; 
    dist[source] = 0;
    pq.push(ii(source,0)); 
    
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
    
    return dist[destination];
}
