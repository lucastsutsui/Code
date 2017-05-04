#include <bits/stdc++.h>
#define el '\n'
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a,b,cont=0;
	cin >> a >> b;
	while (a <= b){
	    a *= 3; b *= 2;
	    cont++;
	}
	cout << cont << el;
	
    return 0;
}
