#include <bits/stdc++.h>
#define max(a,b) (((a)>(b))? (a) : (b))
#define N1 1234567
#define N2 123456
#define N3 1234
using namespace std;

int test (int n){
  for (int i = 0; i <= n; i+=N1)
    for (int j = 0; j <= n; j+=N2)
      if (n-i-j>=0 && (n-(i+j))%N3==0) return true;
  return false;
}

int main ()
{
  int n;

  cin >> n;

  cout << (test(n)? "YES\n" : "NO\n");

  return 0;
}
