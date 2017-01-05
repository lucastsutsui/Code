#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, m;
  long long int cont = 0;

  cin >> n >> m;

  for (int i = 1; i <= n; i++){
    int aux = i % 5;
    cont += (m+aux)/5;
  }

  cout << cont << endl;	

  return 0;
}
