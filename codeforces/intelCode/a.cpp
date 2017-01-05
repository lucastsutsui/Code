#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n,h,m;

  scanf ("%d %d:%d", &n, &h, &m);

  if (n == 12){
    if (h/10 >= 2){
      if (h%10==0) h = 10;
      else h = h%10;
    }
    if (h/10 == 1 && h%10 > 2) h -= (h%10)-1;
    if (h==0) h = 1;
  }
  else{
    if (h/10 >= 3) h = h%10;

    if (h/10 == 2 && h%10 > 3) h -= (h%10);
  }

  if (m/10 >= 6) m = m%10;

  printf ("%02d:%02d\n", h, m);

  return 0;
}
