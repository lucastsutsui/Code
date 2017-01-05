#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, p, num;
  int piz[25], tem[25];
  int dp[25][35];

  while (cin >> n && n){
    cin >> p;

    for (int i = 0; i < n; i++)
      cin >> tem[i] >> piz[i];

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= p; i++) dp[0][p] = 0;

    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= p; j++){
	dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	if (j >= piz[i-1] && dp[i][j] < dp[i-1][j-piz[i-1]] + tem[i-1])
	  dp[i][j] = dp[i-1][j-piz[i-1]] + tem[i-1];
      }
    }

    cout << dp[n][p] << " min.\n";
  }

  return 0;
}
