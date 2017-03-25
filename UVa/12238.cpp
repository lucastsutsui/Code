#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
 
typedef vector<int> vi;
 
int fat[MAX];
int sfat[MAX];
int lev[MAX];
long long dist[MAX], ml, divi;
vector<vi> graf(MAX);
 
void buildSuper (int i, int ansc){
  sfat[i] = ansc;
 
  if (lev[i] % divi == 0) ansc = i;
 
  for (int j = 0; j < graf[i].size(); j++)
    if (graf[i][j] != fat[i]) buildSuper(graf[i][j], ansc);
}
 
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
 
int main() 
{
  ios_base::sync_with_stdio(0); cin.tie(0);
 
  int n, a, q, s, t;
  long long l;
 
  while (true){
    cin >> n;
    if (!n) break;
 
    for (int i = 0; i < n; i++) graf[i].clear();
 
    fat[0] = 0;
    lev[0] = 0;
    ml = 0;
 
    for (int i = 1; i < n; i++){
      cin >> a >> l;
 
      fat[i] = a;
      dist[i] = dist[a] + l;
      lev[i] = lev[a] + 1;
 
      graf[i].push_back(a); 
      graf[a].push_back(i);
 
      if (lev[i] > ml) ml = lev[i];
    }
 
    divi = sqrt(ml);
    buildSuper(0,0);
    cin >> q;
 
    for (int i = 0; i < q; i++){
      if (i != 0) cout << ' ';
      cin >> s >> t;
      cout << dist[s] - 2ll*dist[findLca(s,t)] + dist[t];
    }
 
    cout << '\n';
  }
 
  return 0;
}
