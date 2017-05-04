#include <bits/stdc++.h>
using namespace std;

int n, v[20][20], memo[20][262147];

int solve(int day, int state){
    if (day == n) return 0;
    if (memo[day][state] != -1) return memo[day][state];
    int best = 18000000;
    for (int i = 0; i < n; i++)
        if ((state & (1 << i)) == 0) best = min(best, v[i][day] + solve(day+1, (state|(1 << i))));
    memo[day][state] = best;
    return best;
}

int main() 
{
	while (true){
    	scanf ("%d", &n);
    	memset(memo, -1, sizeof memo);
    	if (n==0) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) scanf ("%d", &v[i][j]);
        printf ("%d\n", solve(0,0));
	}
	return 0;
}