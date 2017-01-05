#include <stdio.h>
#include <iostream>
using namespace std;

int main ( )
{
  long long int n, m, i, total;
  long long int a, b;

  cin >> n;
  cin >> m;
  
  total = 0;

  cin >> a;

  total += (a - 1);

  for (i = 1; i < m; i++){
    cin >> b;

    if (a <= b)
      total += b - a;
    else{
      total += n - a;
      total += b;
    }
      
    a = b;

  }
  
  cout << total;

  return 0;
}
