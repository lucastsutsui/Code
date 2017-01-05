#include <bits/stdc++.h>
using namespace std;
#define TAM 5000
#define WRONG 2000

int main ()
{
  srand(1221);
  bitset<TAM+1> v;
  char c;

  for (int i = 0; i < TAM; i++) v[i] = rand()%2;

  while (1){
    int cont = 0;
    for (int i = 0; i < TAM; i++){
      c = getchar();
      if ((int)(c-'0') != (int)v[i]) cont++;
      if (cont == WRONG) cout << i+1 << endl;
    } getchar();
  }

  return 0;
}
  
