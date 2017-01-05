#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long unsigned int llu;

llu pown (llu a, llu n){
  llu ret = 1;
  a = a%MOD;
  while (n>0){
    if (n%2 == 1)
      ret = (ret*a)%MOD;
    n = n>>1;
    a = (a*a)%MOD;
  }
  return ret;
}

llu inv (llu x){
  return pown (x,MOD-2);
}

int main ()
{
  llu a, b, n, x, gn, sec, an;

  cin >> a >> b >> n >> x;

  if (a==1){
    cout << (x+n*b%MOD)%MOD << endl;
  }
  else{
    an = pown(a, n);
    gn = ((an%MOD)*(x%MOD))%MOD;
    sec = (((an-1)%MOD)*(inv(a-1)%MOD))%MOD;
    sec = ((sec%MOD)*(b%MOD))%MOD;
    cout << (gn+sec)%MOD << endl;
  }

  return 0;
}
