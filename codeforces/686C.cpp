#include <bits/stdc++.h>
using namespace std;

void sub(string &a){
  int k = 0;

  if (a[k]=='0'){
    while (k < a.size() && a[k] == '0'){
      a[k] = '6';
      k--;
    }
    if (k < a.size()) a[k]--;
  }
  else a[k]--;
}

int test (string &a, string &b){
  string aux;
  int in[9];
  aux.append(a);
  aux.append(b);

  for (int i = 0; i < 8; i++) in[i] = 0;
  
  for (int i = 0; i < aux.size(); i++) in[aux[i]-'0']++;

  sub(b);

  for (int i = 0; i < 7; i++) if (in[i] > 1) return 0;

  return 1;
}      

int main ()
{
  int n, m, total=0, aux;
  string a, b;

  cin >> n >> m;
  
  aux = n;
  while (aux){
    a.push_back((aux%7)+'0');
    aux /= 7;
  }
  aux = m;
  while (aux){
    b.push_back((aux%7)+'0');
    aux/=7;
  }

  for (int i = 0; i < n; i++){
    string c;
    c.append(b);
    
    for (int j = 0; j < m; j++)
      total += test(a,b);
    
    b.clear();
    b.append(c);
    sub(a);
  }

  cout << total << endl;

  return 0;
}
