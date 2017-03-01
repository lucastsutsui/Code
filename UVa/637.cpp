#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, s;
	vector<pair<int,int> > v;
	while(true){
	    scanf("%d", &n);
	    if (n == 0) break;
	    s = n/4;
	    if (s*4 < n) s++;
	    v.clear();
	    int page = 1;
	    while (v.size() < 2*s){
	        v.push_back(make_pair(0,page));
	        if (page+1 > n) break;
	        v.push_back(make_pair(page+1,0));
	        page+=2;
	        if (page > n) break;
	    }
	    for (int i = v.size()-1; page <= n && i > 0; i-=2){
	        v[i].second = page;
	        if (page+1 > n) break;
	        v[i-1].first = page+1;
	        page+=2;
	    }
	    printf("Printing order for %d pages:\n", n);
	    for (int i = 0; i < v.size(); i++){
	        if (i%2==0){
	            printf("Sheet %d, front: ", i/2+1);
	            if (v[i].first == 0) printf("Blank, ");
	            else printf("%d, ", v[i].first);
	            if (v[i].second == 0) printf("Blank\n");
	            else printf("%d\n", v[i].second);
	        }
	        else{
	            printf("Sheet %d, back : ", i/2+1);
	            if (v[i].first == 0) printf("Blank, ");
	            else printf("%d, ", v[i].first);
	            if (v[i].second == 0) printf("Blank\n");
	            else printf("%d\n", v[i].second);
	        }
	    }
	}
	return 0;
}