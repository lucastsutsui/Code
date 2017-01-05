#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,dist, x;
    string dir;
    bool flag = true;
    
    cin >> n;
    
    x = 0;
    for (int i = 0; i < n; i++){
        cin >> dist >> dir;
        
        if (x == 0 && dir != "South") flag = false;
        if (x == 20000 && dir != "North") flag = false;
        
        if (dir == "South") x += dist;
        else if (dir == "North") x -= dist;
        
        if (x < 0 || x > 20000) flag = false;
    }
    
    if (x != 0) flag = false;
    
    if (flag) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
