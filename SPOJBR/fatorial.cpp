#include <bits/stdc++.h>
#define MOD 100000
using namespace std;

char v[1000001];

int main() 
{
	int n, teste=1;
	long long int f = 1;
	for (int i = 1; i <= 1000000; i++){
	    f = (f*1ll*i);
	    while (f%10 == 0) f /= 10;
	    f = f%MOD;
	    v[i] = f%10;
	}
	while (scanf("%d", &n) != EOF)
	    printf ("Instancia %d\n%d\n\n", teste++, v[n]);
	return 0;
}
