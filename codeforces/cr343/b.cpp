#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, b, e, max;
  int f[380]={0};
  int m[380]={0};
  char op;

  scanf ("%d", &n);

  for (int i = 0; i < n; i++){
    getchar();
    scanf ("%c %d %d", &op, &b, &e);
    if (op == 'F')
      for (int j = b; j <= e; j++) f[j]++;
    else
      for (int j = b; j <= e; j++) m[j]++;
  }

  max=0;
  for (int i = 0; i <= 379; i++){
    if (m[i] == f[i] && m[i] > max){
      //cout << i << endl;
      max = m[i];
    }
  }

  cout << 2*max << endl;

  return 0;
}
