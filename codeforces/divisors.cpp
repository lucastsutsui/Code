#include <iostream>

using namespace std;

int main ( )
{
  int n, x, pode = 1;
  int num[8];
 
  for (int i = 1; i <= 7; i++) num[i] = 0;

  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> x;
    num[x]++;
  }

  if (num[7] != 0) pode = 0;
  if (num[6] + num[4] != n/3) pode = 0;
  if (num[2] + num[3] != n/3 || num[3] > num[6]) pode = 0;
  if (num[1] != n/3) pode = 0;

  if (!pode)
    cout << -1;
  else{
    for (int i = 0; i < n/3; i++){
      if (i) cout << '\n';
      cout << 1;
      cout << ' ';
      
      if (num[2]){
	cout << 2;
	cout << ' ';
	if (num[4]){
	  cout << 4;
	  num[4]--;
	}
	else if (num[6]){
	  cout << 6;
	  num[6]--;
	}
	num[2]--;
      }
      else if (num[3]){
	cout << 3;
	cout << ' ';
	cout << 6;
	num[3]--;
	num[6]--;
      }
    }
  }
      

  return 0;
}
