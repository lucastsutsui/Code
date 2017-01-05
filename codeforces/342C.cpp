#include <iostream>
#include <math.h>

using namespace std;

int main ( )
{
  int r, h, cont = 0;

  cin >> r >> h;

  cont = (h/r);
  cont *= 2;
  h = h%r;
  if ((float)h >= (float)(r*sqrt(3)/2.0)) cont+=3;
  else if ((float)h >= (float)r/2) cont+=2;
  else cont++;
  
  cout << cont;
  
  return 0;
}
