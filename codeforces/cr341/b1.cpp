#include <iostream>
#include <stdio.h>
#define max(a,b) (((a) > (b))? (a) : (b))
#define min(a,b) (((a) > (b))? (b) : (a))
#define abs(a) (((a) > 0)? (a) : -(a))
using namespace std;

typedef long long int lld;

int check (int xi, int xj, int yi, int yj){
  if (abs(xi-xj) == abs(yi-yj)) return 1;
  return 0;
}

int main ()
{
  int n;
  int x[212123], y[212123];
  lld cont = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
      if (check(x[i], x[j], y[i], y[j])) cont++;
    }
  }

  cout << cont << endl;

  return 0;
}