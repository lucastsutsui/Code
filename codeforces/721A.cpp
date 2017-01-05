#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n;
  string s;
  vector<int> v;

  cin >> n;
  cin >> s;


  for (int i = 0; i < s.size(); i++){
    int cont = 0;
    while (i < s.size() && s[i] == 'B'){ i++; cont++; }
    if (cont) v.push_back(cont);
  }

  cout << v.size() << endl;

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';

  return 0;
}
