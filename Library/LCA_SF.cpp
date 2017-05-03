/* Finds Lowest Common Ancestor between two vertices in a tree */
/* Using Super Father method = O(V*sqrt(V))                    */
 
int fat[MAX];
int sfat[MAX];
int lev[MAX];
long long dist[MAX], maxLev, divi;
vector<vii> graf(MAX);              // graf has adjacent list = pair(vertex, weight)

void buildTree (int i, int ansc, int level, long long d){
  if (level > maxLev) maxLev = level;

  fat[i] = ansc;
  lev[i] = level;
  dist[i] = d;

  for (int j = 0; j < graf[i].size(); j++)
    if (graf[i][j].first != fat[i]) buildTree(graf[i][j].first, i, level+1, d + 1ll*graf[i][j].second);
}
 
void buildSuper(int i, int ansc){
  sfat[i] = ansc;
 
  if (lev[i] % divi == 0) ansc = i;
 
  for (int j = 0; j < graf[i].size(); j++)
    if (graf[i][j].first != fat[i]) buildSuper(graf[i][j].first, ansc);
}

// Returns lowest common ancestor from vertices x and y
int findLca(int a, int b){
  while (sfat[a] != sfat[b]){
    if (lev[a] > lev[b]) a = sfat[a];
    else b = sfat[b];
  }
  while (a != b){
    if (lev[a] > lev[b]) a = fat[a];
    else b = fat[b];
  }
  return a;
}

// Returns distance from vertex x to vertex y
long long di(int x, int y){
  return dist[x] - 2ll*dist[findLca(x,y)] + dist[y];
}
