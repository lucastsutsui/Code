#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int num,ans;
	bitset<18111> secs;
	
	while (true){
	    secs.set();
	    scanf ("%d", &num);
	    if (num == 0) break;
	    while (num){
	        for (int i = num; i <= 18002; i+=(2*num)) 
	            for (int j = i-4; j <= 18002 && j <= i+num; j++) secs[j] = 0;
	        scanf ("%d", &num);
	    }
	    ans = 0;
	    while (ans <= 18002 && secs[ans++]);
	    while (ans <= 18002 && secs[ans] == 0) ans++;
	    ans--;
	    if (ans > 18000) puts("Signals fail to synchronise in 5 hours");
	    else printf("%.2d:%.2d:%.2d\n", ans/3600, (ans/60)%60, ans%60);
	}
	return 0;
}