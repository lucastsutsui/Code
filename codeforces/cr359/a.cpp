#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, q, dc=0;
  long long int x;
  char op;

  scanf ("%d %lld", &n, &x);

  while (n--){
    scanf (" %c %d", &op, &q);
    if (op == '+') x += q;
    else{
      if (x >= q) x-=q;
      else dc++;
    }
  }

  printf ("%lld %d\n", x, dc);

  return 0;
}
