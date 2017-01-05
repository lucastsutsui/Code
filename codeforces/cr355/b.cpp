#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
int main ()
{
  lld n, h, k, a, curr;
  lld cont = 0;
  bool control;

  cin >> n >> h >> k;

  curr = 0;
  for (int i = 0; i < n; i++){
    cin >> a;

    if (curr+a > h){
      lld aux = (a-(h-curr))/k;
      if ((curr+a) - (aux*k) > h) aux++;
      curr-=(aux*k);
      cont+=aux;
    }
    if (curr<0) curr=0;

    curr += a;
  }

  if (curr > 0){
    lld aux = curr/k;
    if (aux*k < curr) aux++;
    cont+=aux;
  }
  
  cout << cont << endl;

  return 0;
}
