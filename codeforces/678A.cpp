#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, k;

  cin >> n >> k;

  n++;
  if (n%k!=0) n += (k-(n%k));
  cout << n << endl;

  return 0;
}
