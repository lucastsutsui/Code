#include <bits/stdc++.h>
using namespace std;

int m,d;
unsigned int mask[22];

int dfs(int i, int qt, int state){
    if (i == d){
        if (__builtin_popcount(state) >= m) return qt;
        else return INT_MAX;
    }
    return min(dfs(i+1,qt+1,state|mask[i]), dfs(i+1,qt,state));
}

int main() 
{
    int t,c;
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&m,&d);
        for (int i = 0; i < d; i++){
            mask[i] = 0;
            scanf("%d",&c);
            for (int j = 0; j < c; j++){
                int num;
                scanf("%d",&num);
                mask[i] |= (1 << num);
            }
        }
        int ret = dfs(0,0,0);
        if (ret == INT_MAX) puts("Desastre!");
        else printf("%d\n", ret);
    }
	return 0;
}
