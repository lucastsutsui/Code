#include <iostream>
using namespace std;

int main ()
{
  int n, a, b, c, d, w=0;

  cin >> n;
  
  for (int i = 0; i < 4; i++){
    cin >> a >> b >> c >> d;
    
    if (!w){
      if (a + c <= n){
	cout << i+1 << ' ' << a << ' ' << (n-a) << endl;
	w = 1;
      }
      else if (a + d <= n){
	cout << i+1 << ' ' << a << ' ' << (n-a) << endl;
	w = 1;
      }
      else if (b + c <= n) {
	cout << i+1 << ' ' << b << ' ' << (n-b) << endl;
	w = 1;
      }
      else if (b + d <= n){
	cout << i+1 << ' ' << b << ' ' << (n-b) << endl;
	w = 1;
      }
    }
  }

  if (!w) cout << -1 << endl;

  return 0;
}
