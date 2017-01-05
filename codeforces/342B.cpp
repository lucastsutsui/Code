#include <iostream>

using namespace std;

int main ( )
{
  int n, m, s, f;
  int t, l, r;
  int cont = 1;

  cin >> n >> m >> s >> f;
  
  while(m--){
    cin >> t >> l >> r;

    while (s != f && cont < t){
      if (s > f){
	cout << 'L';
	s--;
      }
      else{
	cout << 'R';
	s++;
      }
      cont++;
    }
    
    if (s != f && cont == t){
      if ((s <= r && s >= l) || (s > f && s == r+1) || (s < f && s == l-1)){
	cout << 'X';
	cont++;
      }
      else if (s > f){
	cout << 'L';
	s--;
	cont++;
      }
      else{
	cout << 'R';
	s++;
	cont++;
      }
    }
  }

  while (s > f){
    cout << 'L';
    s--;
  }
  while (s < f){
    cout << 'R';
    s++;
  }
  
  return 0;
}
