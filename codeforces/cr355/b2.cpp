#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, h, k, a, curr;
  int cont = 0;
  queue<int> s;

  cin >> n >> h >> k;

  for (int i = 0; i < n; i++){
    cin >> a;
    s.push(a);
  }

  curr=0;
  while (1){
    if (curr == 0 && s.size() == 0) break;
    
    if (curr + s.front() > h){
      curr -= (s.front()/k)*k;
      cont += (s.front()/k);
      if (curr < 0) curr=0;
      if (curr + s.front() > h){
	curr-=k;
	cont++;
      }
      if (curr < 0) curr=0;
    }
    
    curr += s.front();
    s.pop();
  }

  cout << cont << endl;

  return 0;
}
