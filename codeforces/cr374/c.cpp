#include <bits/stdc++.h>
using namespace std;

#define mk make_pair
#define pb push_back
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> graph (5001);
int n, m, t;

int main ()
{
  int u, vi, ti;
  queue<State> q;
  State curr;

  cin >> n >> m >> t;

  for (int i = 0; i < m; i++){
    cin >> u >> vi >> ti;
    graph[u].pb(mk(vi,ti));
    graph[vi].pb(mk(u,ti));
  }

  
  
  cout << final.size() << endl;
  for (int i = 0; i < final.size(); i++)
    cout << final[i] << ' ';
  cout << endl;
  
  return 0;
}
