#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int n, s, d;
	scanf("%lld", &n);
	while (n--){
	    scanf("%lld%lld", &s, &d);
	    long long int a = (s+d)/2;
	    long long int b = s-a;
	    if (a+b != s || a-b != d || a<0 || b<0) puts("impossible");
	    else printf("%lld %lld\n", a, b);
	}
	return 0;
}