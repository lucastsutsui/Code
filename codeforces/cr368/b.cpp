#include <bits/stdc++.h>
using namespace std;

typedef struct{
  int v;
  int u;
  int w;
}Edge;

bool my_cmp (const Edge &a, const Edge &b){
  return a.w < b.w;
}

#define max(a,b) (((a)>(b))? (a) : (b))
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)

typedef long long unsigned int llu;
typedef long long int lld;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main ()
{
  int n, m, k, u, v, l, num;
  vector<Edge> eds;
  vector<int> bak;

  sc3(n,m,k);

  rep(i,m){
    Edge aux;
    cin >> u >> v >> l;
    aux.v = u;
    aux.u = v;
    aux.w = l;
    eds.pb(aux);
  }

  rep(i,k){
    cin >> num;
    bak.pb(num);
  }

  sort(eds.begin(), eds.end(), my_cmp);
  sort(bak.begin(), bak.end());

  int mn = -1;
  for (int i = 0; i < eds.size(); i++){
    int n1 = (lower_bound(bak.begin(), bak.end(), eds[i].v) - bak.begin());
    int n2 = (lower_bound(bak.begin(), bak.end(), eds[i].u) - bak.begin());

    if (((n1 >= bak.size() || bak[n1] != eds[i].v) && (n2 < bak.size() && bak[n2] == eds[i].u)) || ((n1 < bak.size() && bak[n1] == eds[i].v)&& (n2 >= bak.size() || bak[n2] != eds[i].u))){
      if (mn==-1) mn = eds[i].w;
      else mn = min(mn,eds[i].w);
    }    
  }

  cout << mn << endl;

  return 0;
}
