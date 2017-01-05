#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int lld;

int zero (char n){
  int cont = 0;
  for (int i = 0; i < 6; i++) if ((n&(1<<i)) == 0) cont++;
  return cont;
}

int main ()
{
  char v[112123];
  char t;
  int i=0;
  lld cont=1;


  while (1){
    t = getchar();
    if (t == EOF || t == '\n') break;
    else if (t >= '0' && t <= '9') v[i] = (t-'0');
    else if (t >= 'A' && t <= 'Z') v[i] = (10+t-'A');
    else if (t >= 'a' && t <= 'z') v[i] = (36+t-'a');
    else if (t == '-') v[i] = 62;
    else v[i] = 63;
    i++;
  }

  for (int j = 0; j < i; j++) cont = ((cont%MOD)*((lld)pow(3,zero(v[j]))%MOD))%MOD;
    
  cout << cont%MOD << endl;
  
  return 0;
}
