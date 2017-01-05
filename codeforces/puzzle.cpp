#include <iostream>
#include <limits.h>
using namespace std;

int separa (int p, int r, int v[]){
  int x, i, j, aux;
  
  x = v[p];
  i = p-1;
  j = r+1 ;
  
  while (1){
    do{
      j--;
    }while (v[j] > x);
    do{
      i++;
    }while (v[i] < x);
    if (i < j){
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
    }
    else return j;
  }
}

void quick (int p, int r, int v[]){
  int q;
  
  if (p < r){
    q = separa (p, r, v);
    quick (p, q, v);
    quick (q+1, r, v);
  }
}

int main ( )
{
  int n, m, min;
  int f[55];

  cin >> n >> m;

  for (int i = 0; i < m; i++) cin >> f[i];

  quick (0, m-1, f);

  min = INT_MAX;
  for (int i = 0; i+n-1 < m; i++)
    if (f[i+n-1] - f[i] < min) 
      min = f[i+n-1] - f[i];

  cout << min;

  return 0;
}
