#include <bits/stdc++.h>
using namespace std;
#define max(a,b) (((a) > (b))? (a) : (b))

int main ()
{
  int n;
  int v[123];
  int maxi, mini;
  int tot;

  cin >> n;

  maxi = 0;
  mini = 0;
  for (int i = 0; i < n; i++){
    cin >> v[i];
    if (v[i] > v[maxi])
      maxi = i;
    else if (v[i] < v[mini])
      mini = i;
  }

  tot = abs(maxi-mini);
  if (maxi > mini){
    tot = max(tot,n-1-mini);
    tot = max(tot,maxi);
  }
  else{
    tot = max(tot,n-1-maxi);
    tot = max(tot,mini);
  }
  cout << tot << endl;
  /*  if (maxi > mini){
    if (n-maxi > mini) cout << (n-1)-mini << endl;
    else cout << maxi-1 << endl;
  }
  else{
    if (n-mini > maxi) cout << (n-1)-maxi << endl;
    else cout << mini-1 << endl;
    }*/

  return 0;
}
