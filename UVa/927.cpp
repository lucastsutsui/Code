#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int C, I, c[30], d, k;
    
    cin >> C;
    for (int test = 0; test < C; test++){
        cin >> I;
        for (int i = 0; i <= I; i++) cin >> c[i];
        cin >> d >> k;
        
        int index = 1;
        while (k > 0){
            k -= index*d; index++;
        }
        index--;
        long long ans = 0, ex = 1;
        for (int i = 0; i <= I; i++) {
            ans += c[i]*1LL*ex;
            ex *= index;
        }
        cout << ans << '\n';
    }
    
	return 0;
}