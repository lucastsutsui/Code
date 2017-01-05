#include <iostream>
#include <stdio.h>
#define max(a,b) (((a) > (b))? (a) : (b))
#define min(a,b) (((a) > (b))? (b) : (a))
using namespace std;

typedef long long int lld;

int main ()
{
  int n, imp=0, num;
  int v[112123], tam=0;
  lld sum=0;

  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> num;
    sum += num;
    if (num%2==1){
      imp++;
      v[tam] = num;
      tam++;
    }
  }

  if (imp%2 == 1){
    int min = v[0];
    for (int i = 1; i < tam; i++)
      if (v[i] < min) min = v[i];
    sum -= min;
  }

  cout << sum << endl;

  return 0;
}
