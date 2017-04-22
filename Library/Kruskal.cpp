
typedef struct{ 
    //Represents an edge from u to v with weight equals to w
    int v, u, w; 
}Edge;

bool my_comp (const Edge &a, const Edge &b){ return a.w < b.w; }

int find (int i){
    if (parent[i] == i) return i;
    return (parent[i] = find(parent[i]));
}

void unite (int a, int b){
    a = find(a);
    b = find(b);
    if (sz[a] > sz[b]) parent[b] = a;
    else{
        parent[a] = b;
        if (sz[a] == sz[b]) sz[b]++;
    }
}

void kruskal(){
    sort (eds.begin(), eds.end(), my_comp); // eds is the vector<Edge> containing all edges from the graph
    
    for (int i = 0; i < n; i++){
        sz[i] = 0;
        parent[i] = i;
    }
    
    for (int i = 0; i < eds.size(); i++){
        if (find(eds[i].v) != find(eds[i].u)){
        
            // Saves in *ret* all edges from the MST
            if (eds[i].v < eds[i].u) ret.pb(ii(eds[i].v, eds[i].u));
            else ret.pb(ii(eds[i].u, eds[i].v));

            // Saves in *total* the cost of the MST
            total += eds[i].w;
            
            unite(find(eds[i].v), find(eds[i].u));
        }
    }
}
