#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, n, cont,num, j, test=1;
	int v[52],w[140];
	scanf("%d", &t);
	while (t--){
	    scanf("%d", &n);
	    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	    sort(v, v+n);
	    int beg = 70, end = 72, ij = 1, ik = n-2;
	    w[beg] = v[0]; w[beg+1] = v[n-1];
	    
	    while (ij <= ik){
	        int max=abs(w[beg]-v[ij]), id=0;
	        if (abs(w[beg]-v[ik]) > max){ max = abs(w[beg]-v[ik]); id = 1; }
	        if (abs(w[end-1]-v[ij]) > max){ max = abs(w[end-1]-v[ij]); id = 2; }
	        if (abs(w[end-1]-v[ik]) > max){ max = abs(w[end-1]-v[ik]); id = 3; }
	        
	        if (id == 0) w[--beg] = v[ij++];
	        else if (id == 1) w[--beg] = v[ik--];
	        else if (id == 2) w[end++] = v[ij++];
	        else w[end++] = v[ik--];
	    }
	    cont = 0;
	    for (int i = beg+1; i < end; i++) cont += abs(w[i]-w[i-1]);
	    printf("Case %d: %d\n", test++, cont);
	}
	return 0;
}