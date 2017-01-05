#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a)>(b))? (a) : (b))
#define min(a,b) (((a)<(b))? (a) : (b))
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

int m[212123];

int main ()
{
  int n;
  int v[212123];
  vector<int> a[212123];
  bool vis[212123];
  queue<int> q;
  sc(n);

  rep(i,n){
    sc(v[i]);
    m[i] = i;
    if (i>0) a[i].pb(i-1);
    if (i < n-1) a[i].pb(i+1);
    a[i].pb(v[i]-1);
    vis[i] = false;
  }

  q.push(0);
  while (!q.empty()){
    int curr = q.front();
    q.pop();
    vis[curr] = true;
    for (int i = 0; i < a[curr].size(); i++){
      if(!vis[a[curr][i]]){
	m[a[curr][i]] = min(m[a[curr][i]], m[curr]+1);
	q.push(a[curr][i]);
	vis[a[curr][i]] = true;
      }
    }
  }
  
  rep(i,n) cout << m[i] << ' ';
  cout << endl;

  return 0;
}
