#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n;
  cin >> n;

  while (n--){
    int k;
    bool flag = false;
    string ans, str;
    
    cin >> k;
    cin >> ans;
    for (int i = 1; i < k; i++){
      cin >> str;
      if (str.compare(ans) != 0) flag = true;
    }

    if (!flag) cout << ans << endl;
    else cout << "ingles\n";

  }

  return 0;
}
