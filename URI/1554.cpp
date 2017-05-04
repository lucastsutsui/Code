#include <bits/stdc++.h>
#define EPS 0.01
using namespace std;

int main() 
{
	int c,n,x,y,xb,yb;
	scanf ("%d", &c);
	while (c--){
	    int ans=0;
	    double dist = hypot(1420, 2840);
	    scanf ("%d", &n);    
	    
	    scanf ("%d %d", &xb, &yb);
	    for (int i = 0; i < n; i++){
	        scanf ("%d %d", &x, &y);
	        if (dist > hypot(abs(xb-x), abs(yb-y))+EPS){
	            ans = i+1;
	            dist = hypot(abs(xb-x), abs(yb-y));
	        }
	    }
	    
	    printf("%d\n", ans);
	}
	return 0;
}
