#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, t;
  double n1[11] = {0.0};
  int cont = 0;

  cin >> n >> t;

  n1[0] = t;
  if (n1[0] >= 1.0) cont++;
  for (int i = 1; i < n; i++){
    double n2[11] = {0.0};

    for (int j = 0; j < i; j++){
      if (n1[j] >= 1.0){
	n1[j]-=1.0;
	n2[j] += (n1[j])/2.0;
	n2[j+1] += (n1[j])/2.0;
      }
    }

    for (int j = 0; j < i+1; j++){
      if (n2[j] >= 1.0) cont++;
      n1[j] = n2[j];
    }
  }

    cout << cont << endl;
  
  return 0;
}
