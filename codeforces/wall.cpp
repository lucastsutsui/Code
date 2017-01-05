#include <iostream>

using namespace std;

int mdc (long int a, long int b){
  if (b == 0) return a;
  return mdc (b, a%b);
}

int main ( )
{
  long long int x, y, a, b, cont = 0, m, i;

  cin >> x >> y >> a >> b;

  m = (x*y)/mdc (x, y);
  
  i = a - (a%m);
  
  if (a%m == 0) cont++;
  
  cont += (b-i)/m;
  
  cout << cont;

  return 0;
}
