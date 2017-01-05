#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define max(a,b) (((a) > (b))? (a) : (b))
#define min(a,b) (((a) > (b))? (b) : (a))
using namespace std;

typedef long long int lld;

int main ()
{
  int n, p;
  unsigned int l[112123], r[112123];
  double exp=0.0;

  cin >> n >> p;

  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];

  int beg = 0, end = 1, flag=0;
  while (1){
    if (beg == 0){
      if (flag) break;
      else flag = 1;
    }

    int v1=0, v2=0;
    v1 = (r[beg]/p) - ((l[beg]-1)/p);
    v2 = (r[end]/p) - ((l[end]-1)/p);
    //cout << v1 << " " << v2 << endl;
    
    lld aux1, aux2, aux3, aux4;
    aux1 = (lld)(v1) * (lld)(r[end] - (l[end]-1));
    aux2 = (lld)(v2) * (lld)(r[beg] - (l[beg]-1));
    aux3 = (lld)(v2) * (lld)(v1);
    aux4 = (lld)(r[end] - (l[end]-1)) * (lld)(r[beg] - (l[beg]-1));
    //cout << aux1 << " " << aux2 << " " << aux3 << " " << aux4 << endl;
    exp += 1000.0 * (double)(aux1 + aux2 - aux3) / (double)aux4;
    beg = end;
    end = (end+1)%n;
  }

  printf ("%.10lf\n", 2.0*exp);

  return 0;
}
