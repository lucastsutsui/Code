#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int testes, n, k, r;
  int c[55], v[55];
  int dp[55][105];

  cin >> testes;

  while (testes--){
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> v[i] >> c[i];

    cin >> k >> r;

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= k; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= k; j++){
	dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	if (j >= c[i-1] && dp[i][j] < dp[i-1][j-c[i-1]] + v[i-1])
	  dp[i][j] = dp[i-1][j-c[i-1]] + v[i-1];
      }
    }

    if (dp[n][k] >= r) cout << "Missao completada com sucesso\n";
    else cout << "Falha na missao\n";
  }

  return 0;
}
