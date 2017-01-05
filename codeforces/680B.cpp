#include <bits/stdc++.h>
#define min(a,b) (((a)<(b))? (a) : (b))
#define max(a,b) (((a)>(b))? (a) : (b))
typedef long long int lld;
typedef long long unsigned int llu;

using namespace std;

int main ()
{
  int a,n,num;
  int t[123]={0};

  cin >> n >> a;

  for (int i = 1; i <= n; i++){
    cin >> num;
    if (num == 1)
      t[abs(i-a)]++;
  }

  int max_range = min(a-1,(n-a));
  int sum = 0;
  
  for (int i = 0; i <= 100; i++){
    if (i == 0)
      sum += t[i];
    else if (i <= max_range && t[i] == 2)
      sum += 2;
    else if (i > max_range)
      sum += t[i];
  }

  cout << sum << endl;

  return 0;
}
