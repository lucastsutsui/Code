#include <iostream>
#include <stdlib.h>
using namespace std;

int maxi = INT_MIN, g[112];

int f (int c[], int n, int i, int val, int k){
  if (i == n){
    if (val == 0 && k) return 1;
    return 0;
  }
  
  if (
  return f(c, n, i+1, val, k) || f(c, n, i+1, val+c[i], k+1);
}

int main ()
{
  int n, k;
  int a[112], b[112], c[112];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    c[i] = a[i] - k*b[i]; //quanto esta sobrando em a

  cout << f (c, n, 0, 0, 0) << endl;

  return 0;
}
