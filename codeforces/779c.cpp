#include <bits/stdc++.h>
#define MAX 200012
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, a[MAX], b[MAX];
    vector<pair<int,int> > d;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    for (int i = 0; i < n; i++) d.push_back(make_pair(a[i]-b[i], a[i]));
    sort(d.begin(), d.end());
    
    int cont=0, in=0;
    while (in < k) cont += d[in++].second;
    while (in < n && d[in].first <= 0) cont += d[in++].second;
    while (in < n){ cont += (d[in].second - d[in].first); in++; }
    cout << cont << '\n';
    return 0;
}