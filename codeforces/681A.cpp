#include <bits/stdc++.h>
#define max(a,b) (((a)>(b))? (a) : (b))
using namespace std;

int main ()
{
  int n, af, be;
  bool flag = false;

  scanf ("%d", &n);
  getchar();
  
  while (n--){
    char c = getchar();
    while (c != ' ') c = getchar();
    scanf ("%d %d", &be, &af);
    getchar();
    if (be >= 2400 && be < af) flag = true;
  }

  cout << (flag? "YES\n" : "NO\n");

  return 0;
}
