#include <bits/stdc++.h>
using namespace std;

int p[112345];
int rk[112345];

int find(int i){
  return (p[i] == i) ? i : (p[i] = find(p[i]));
}

void unite(int i, int j){
  int a = find(i);
  int b = find(j);
  if (a == b) return;
  if (rk[a] > rk[b]) p[b] = a;
  else{
    p[a] = b;
    if (rk[a] == rk[b]) rk[b]++;
  }
}

int main ()
{
  int num, mx, n;
  long long int a[112345];
  int v[112345];
  bool rev[112345];

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++){
    rev[i] = false;
    cin >> v[i];
    p[i] = i;
    rk[i] = 0;
  }

  stack<long long int> p;
  p.push(0);
  mx = v[n-1]-1;
  
  for (int i = n-1; i > 0; i--){
    int curr = v[i] - 1;
    
    if (curr-1 >= 0 && rev[curr-1]){
      int k = find(curr-1);
      int g = find(curr);
      unite(g,k);
      if (find(g) == g) a[g] += a[k];
      else a[find(g)] += a[g];
    }
    if (curr+1 < n && rev[curr+1]){
      int k = find(curr+1);
      int g = find(curr);
      unite(g,k);
      if (find(g) == g) a[g] += a[k];
      else a[find(g)] += a[g];
    }

    rev[curr] = true;
    if (a[find(curr)] > a[mx]) mx = find(curr);
    p.push(a[mx]);
  }

  while (p.size()){
    cout << p.top() << endl;
    p.pop();
  }

  return 0;
}
