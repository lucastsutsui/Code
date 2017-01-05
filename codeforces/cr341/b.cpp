#include <iostream>
#include <string.h>
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
  int x, y;
  int tab1[2001], tab2[2001];
  // int x[212123], y[212123];
  lld cont = 0;

  cin >> n;

  memset(tab1, 0, sizeof(tab1));
  memset(tab2, 0, sizeof(tab2));

  for (int i = 0; i < n; i++){
    cin >> x >> y;
    tab1[x-y+1000]++;
    tab2[y+x]++;
  }

  for (int i = 0; i < 2001; i++){
    if (tab1[i] > 1) cont += (lld)tab1[i] * (lld)(tab1[i]-1) / (lld)2;
    if (tab2[i] > 1) cont += (lld)tab2[i] * (lld)(tab2[i]-1) / (lld)2;
  }

  cout << cont << endl;

  return 0;
}
