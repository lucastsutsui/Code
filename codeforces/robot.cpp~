#include <iostream>

using namespace std;

int main ()
{
  int c1, c2, c3, c4, soma1=0, soma2=0;
  int n, m;
  int a[1001], b[1001], aux[1001];

  cin >> c1 >> c2 >> c3 >> c4;
  cin >> n >> m;
  
  for (int i = 0; i < n; i++){
    cin >> a[i];

    if (a[i]*c1 < c2) soma1 += (a[i]*c1);
    else soma1 += c2;
  }
  if (c3 < soma1) soma1 = c3;

  for (int i = 0; i < m; i++){
    cin >> b[i];

    if (b[i]*c1 < c2) soma2 += (b[i]*c1);
    else soma2 += c2;
  }
  if (c3 < soma2) soma2 = c3;

  if (c4 < soma1+soma2){
    cout << c4 << endl;
    return 0;
  }

  cout << soma1+soma2 << endl;

  return 0;
}
