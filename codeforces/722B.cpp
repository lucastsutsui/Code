#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n;
  int p[102];
  string str;
  bool flag = true;

  scanf ("%d", &n);
  for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
  getchar();
  for (int i = 0; i < n; i++){
    getline(cin,str);
    int cont = 0;
    for (int j = 0; j < str.size(); j++) if (str[j] == 'a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u' || str[j] == 'y') cont++;

    if (cont != p[i]) flag = false;
  }

  if (flag) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
