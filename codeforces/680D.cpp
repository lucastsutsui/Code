#include <bits/stdc++.h>
#define pow3(n) ((n)*(n)*(n))
#define max(a,b) (((a)>(b))? (a) : (b))
typedef long long int lld;
typedef unsigned long long int llu;

using namespace std;

llu maxi;
llu tam;

void find (llu m, llu t, llu sum){
  if (m == 0){
    if (t >= tam){
      if (t == tam)
	maxi = max(maxi,sum);
      else
	maxi = sum;
      tam = t;
    }
    return;
  }
  
  llu aux = (int) cbrt (m);

  find (m-pow3(aux), t+1, sum+pow3(aux));
  find (pow3(aux)-1-pow3(aux-1), t+1, sum+pow3(aux-1));
}

int main ()
{
  llu m;
  tam = 0;
  
  cin >> m;

  find (m, 0, 0);

  cout << tam << ' ' << maxi << endl;

  return 0;
}
