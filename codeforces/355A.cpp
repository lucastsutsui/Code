#include <iostream>

using namespace std;

int main ()
{
  int k, d;
  
  cin >> k >> d;
  
  if (d == 0 && k > 1) cout << "No solution";
  else{
    cout << d;
    k--;
    while (k--) cout << '0';
  }

  return 0;
}
