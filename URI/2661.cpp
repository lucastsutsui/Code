#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

int main() 
{
	lld n;
	cin >> n;
	
	lld lim = sqrt(n)+2;
	lld aux = n, cnt = 0;
	for (lld i = 2; i < lim; i++){
	    if (aux%i == 0){
	        cnt++;
    	    while (aux > 1 && aux%i == 0) aux /= i;
	    }
	    if (aux == 1) break;
	}
	if (aux > 1) cnt++;
	
	if (cnt <= 1) cout << "0\n";
	else cout << ((1LL << cnt) - 1 - cnt) << endl;
	
	return 0;
}
