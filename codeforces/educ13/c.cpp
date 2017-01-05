#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

lld gcd (lld x, lld y){
  return y? gcd (y, x%y) : abs(x);
}

lld lcm (lld x, lld y){
  if (x&&y) return abs(x)/gcd(x,y)*(lld)(abs(y));
  else return (lld)(x|y);
}

int main ()
{
  lld n,a,b,p,q, nump, numq;

  cin >> n >> a >> b >> p >> q;

  nump = n/a;
  numq = n/b; //cout << nump << endl << numq << endl;
  if (p > q){
    //nump += n/lcm(a,b);
    numq -= n/lcm(a,b);
  }
  else{
    nump -= n/lcm(a,b);
    //numq += n/lcm(a,b);
  }//cout << nump << endl << numq << endl;

  printf ("%lld\n", (lld)(nump*p) + (lld)(numq*q));

  return 0;
}
    
