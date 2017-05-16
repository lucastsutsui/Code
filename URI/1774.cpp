#include <bits/stdc++.h>
#define MAX 201
using namespace std;

int parent[MAX], sz[MAX];
int total, r, c;

typedef struct{ 
    int v, u, w; 
}Edge;

vector<Edge> eds;

bool my_comp (const Edge &a, const Edge &b){ return a.w < b.w; }

int find (int i){
    return (parent[i] == i ? i : (parent[i] = find(parent[i])));
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
    sort (eds.begin(), eds.end(), my_comp);
    for (int i = 0; i < c; i++) sz[i] = 0, parent[i] = i;
    
    for (int i = 0; i < eds.size(); i++){
        if (find(eds[i].v) != find(eds[i].u)){
            total += eds[i].w;
            unite(find(eds[i].v), find(eds[i].u));
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    Edge aux;
    
    while (cin >> r >> c){
        eds.clear();
        for (int i = 0; i < c; i++){
            cin >> aux.v >> aux.u >> aux.w;
            aux.v--; aux.u--;
            eds.push_back(aux);
        }
        total = 0;
        kruskal();
        cout << total << '\n';
    }
    
	return 0;
}
