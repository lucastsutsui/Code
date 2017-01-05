#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n;
  long long int cont=0, cont2;
  char v[112][112];

  scanf ("%d", &n);
  getchar();

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      v[i][j] = getchar();
    getchar();
  }

  for (int i = 0; i < n; i++){
    cont2=0;
    for (int j = 0; j < n; j++)
      if (v[i][j] == 'C') cont2++;
    /* while (cont2 > 1){
      cont += cont2-1;
      cont2--;
      }*/
    cont += cont2*(cont2-1)/2;
  }


  for (int i = 0; i < n; i++){
    cont2=0;
    for (int j = 0; j < n; j++)
      if (v[j][i] == 'C') cont2++;
    /*while (cont2 > 1){
      cont += cont2-1;
      cont2--;
    }*/
    cont += cont2*(cont2-1)/2;
  }

  cout << cont << endl;
  return 0;
}
