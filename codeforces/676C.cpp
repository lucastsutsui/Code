#include <bits/stdc++.h>
#define max(a,b) (((a) > (b))? (a) : (b))
using namespace std;

int main ()
{
  int n, k;
  char str[112123], l;
  int va[112123], vb[112123];
  int maxa, maxb;

  cin >> n >> k;
  scanf (" %s", str);

  va[0] = vb[0] = 0;
  for (int i = 0; i <= n; i++){
    va[i] = va[i-1] + ((str[i-1]=='a')? 1 : 0);
    vb[i] = vb[i-1] + ((str[i-1]=='b')? 1 : 0);
  }

  maxa = 0;
  int j=0, g=1;
  while (g <= n){
    if (va[g] - va[j] <= k || g==j){
      maxa = max(maxa,g-j);
      g++;
    }
    else j++;
  }
  j=0; g=1;
  while(g <= n){
    if (vb[g] - vb[j] <= k || g==j){
      maxb = max(maxb,g-j);
      g++;
    }
    else j++;
  }

  cout << max(maxa,maxb) << endl;

  return 0;
}
