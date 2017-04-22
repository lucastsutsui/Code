#include <bits/stdc++.h>
#define MAX 123
#define pb push_back
using namespace std;

typedef struct{
    int v;
    int u;
    int w;
}Edge;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, m;
int parent[MAX];
int sz[MAX];
vii ret;
vector<Edge> eds;

bool my_comp (const Edge &a, const Edge &b){
    return a.w < b.w;
}

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
    sort (eds.begin(), eds.end(), my_comp);
    
    for (int i = 0; i < n; i++){
        sz[i] = 0;
        parent[i] = i;
    }
    
    for (int i = 0; i < eds.size(); i++){
        if (find(eds[i].v) != find(eds[i].u)){
            if (eds[i].v < eds[i].u) ret.pb(ii(eds[i].v, eds[i].u));
            else ret.pb(ii(eds[i].u, eds[i].v));
            unite(find(eds[i].v), find(eds[i].u));
        }
    }
}

int main()
{
  int teste=0, x, y, z;
  Edge aux;
  
  while (1){
      eds.clear();
      ret.clear();
      
      cin >> n >> m;
      if (n==0) break;

      for (int i = 0; i < m; i++){
          cin >> x >> y >> z;
          aux.v = x-1;
          aux.u = y-1;
          aux.w = z;
          eds.push_back(aux);
      }
      
      kruskal();
      
      cout << "Teste " << ++teste << endl;
      for (int i = 0; i < ret.size(); i++)
        cout << ret[i].first+1 << ' ' << ret[i].second+1 << endl;
      cout << endl;
  }
  
  return 0;
}
