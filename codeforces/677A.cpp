#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, h;
  int a, w=0;

  cin >> n >> h;

  for (int i = 0; i < n; i++){
    cin >> a; w++;
    if (a > h) w++;
  }

  cout << w << endl;

  return 0;
}
