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
  int n;
  char num[14];
  sc(n);
  getchar();

  rep(i,n)
    num[i] = getchar();

  bool flag[5];
  
  flag[0] = flag[1] = flag[2] = flag[3] = false;
  rep(i,n){
    if (num[i] == '1' || num[i] == '4' || num[i] == '7' || num[i]=='0') flag[0]=true;
    if (num[i] == '1' || num[i] == '2' || num[i] == '3') flag[1]=true;
    if (num[i] == '3' || num[i] == '6' || num[i] == '9' || num[i]=='0') flag[2]=true;
    if (num[i] == '7' || num[i] == '0' || num[i] == '9') flag[3]=true;
  }

  if (flag[0] && flag[1] && flag[2] && flag[3]) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
