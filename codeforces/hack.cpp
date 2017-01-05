#include <iostream>
#include <limits.h>

using namespace std;

int main ()
{
  int a[1000][1000],n,i,j,p=5,q,w,e,r=0;
  cin >> n;
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      cin >> a[j][i];
    }
  }
  for (i=0;i<4;i++){
    for (j=0;j<2;j++){
      for (e=2;e<4;e++){
	if (a[j][i]+a[e][i] <= n && r==0){
	  p=i;
	  q=a[j][i];
	  w=a[e][i];
	  r++;
	}
      }
    }
  }
  if (q>=w && q+w != n){
    w = n-q;
  }
  else if (w<q && (q+w) != n){
    w = n-q;
  }
  if (p != 5)
    cout << p+1 << " " << q << " " << w;
  else cout << -1;

  return 0;
}
