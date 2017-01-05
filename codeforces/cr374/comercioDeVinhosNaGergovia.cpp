#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n;
  int v[112345];

  while (cin >> n && n){
    for (int i = 0; i < n; i++) cin >> v[i];

    queue<pair<int,int> > vende, compra;
    long long int cont = 0;

    for (int i = 0; i < n; i++){
      if (v[i] >= 0){
	if (compra.size()){
	  while (compra.size() && compra.front().first < v[i]){
	    v[i] -= compra.front().first;
	    cont += (i - compra.front().second)*1ll*compra.front().first;
	    compra.pop();
	  }
	  if (v[i] != 0 && compra.size()){
	    int sav = compra.front().second;
	    cont += (i - sav)*1ll*v[i];
	    v[i] = compra.front().first - v[i];
	    compra.pop();
	    compra.push(make_pair(v[i], sav));
	    v[i] = 0;
	  }
	  else if (v[i] != 0)
	    vende.push(make_pair(v[i],i));
	}
	else vende.push(make_pair(v[i],i));
      }
      else{
	v[i] = -v[i];
	if (vende.size()){
	  while (vende.size() && vende.front().first < v[i]){
	    v[i] -= vende.front().first;
	    cont += (i - vende.front().second)*1ll*vende.front().first;
	    vende.pop();
	  }
	  if (v[i] != 0 && vende.size()){
	    int sav = vende.front().second;
	    cont += (i - sav)*1ll*v[i];
	    v[i] = vende.front().first - v[i];
	    vende.pop();
	    vende.push(make_pair(v[i], sav));
	    v[i] = 0;
	  }
	  else if (v[i] != 0)
	    compra.push(make_pair(v[i],i));
	}
	else compra.push(make_pair(v[i],i));
      }
    }

    cout << cont << endl;
  }

  return 0;
}
