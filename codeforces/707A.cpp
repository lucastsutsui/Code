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

int main ()
{
  int n, m;
  char c;
  bool bw=true;

  sc2(n,m);

  rep(i,n){
    rep(j,m){
      getchar();
      scanf ("%c", &c);
      if (c == 'M' || c == 'Y' || c == 'C') bw = false;
    }
  }

  if (bw) cout << "#Black&White" << endl;
  else cout << "#Color" << endl;

  return 0;
}
