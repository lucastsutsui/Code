#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int k, n;
    cin >> n >> k;
    int i = 1, sum = 0;
    while (i<=n && sum+(i*5)+k <= 240){
        sum += (i*5);
        i++;
    }
    printf ("%d\n", i-1);
    return 0;
}
