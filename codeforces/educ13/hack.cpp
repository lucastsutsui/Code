#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, a, b, p, q;

int main() {
  ios :: sync_with_stdio(0);
  while (cin >> n >> a>> b >> p >> q) {


    cout << (n/a - n/(a*b)) * p + (n/b - n/(a*b)) * q + (n/(a*b)) * max(p,q) << "\n";
  }
  return 0;
}
