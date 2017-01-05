#include <iostream>
#include <limits.h>

using namespace std;

int main ()
{
  int n, k;
  int min, ind;
  int soma;
  int v[112345];
  
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> v[i];

  min = INT_MAX;
  for (int i = 0; i < k; i++){
    soma = 0;
    for (int j = i; j < n; j+=k)
      soma += v[j];
    if (soma < min){
      min = soma;
      ind = i;
    }
  }

  cout << ind+1 << endl;

  return 0;
}
