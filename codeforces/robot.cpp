#include <iostream>
#define dir 0
#define esq 1
#define min(a,b) ((a<b)? a : b)

using namespace std;

int pd (int n, int ql, int qr, int l, int r, int w[], int dp[101][101][2]){
  int i, j;

  for (i = 0; i < n; i++){
    dp[i][i][dir] = min ((w[i] * r) + qr, (w[i] * l));
    dp[i][i][esq] = min ((w[i] * r), (w[i] * l) + ql);
  }

  for (i = 0; i <n; i++){
    for (j = i+1; j < n; j++){
      dp[i][j][esq] = min (dp[i-1][j][esq] + w[i]*l + ql, dp[i][j-1][dir] + w[i]*r);
      dp[i][j][dir] = min (dp[i-1][j][esq] + w[i]*l, dp[i][j-1][dir] + w[i]*r + qr);
    }
  }

  return min(dp[n-1][n-1][dir], dp[n-1][n-1][esq]);
}


int main ()
{
  int n, l, r, ql, qr;
  int w[101];
  int dp[101][101][2];

  cin >> n >> l >> r >> ql >> qr;

  for (int i = 0; i < n; i++) cin >> w[i];

  cout << pd (n, ql, qr, l, r, w, dp) << endl;

  return 0;
}
