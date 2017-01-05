#include <bits/stdc++.h>
using namespace std;

int a,b,c,x,y;

int next(int n){
    n++;
    while (n==a || n==b || n==c || n==x || n==y) n++;
    if (n <= 52) return n;
    return -1;
}

int main()
{   
    while (cin>>a>>b>>c>>x>>y){
        if ((a|b|c|x|y)==0) break;
        
        // sort cards
        if (b>a) swap(b,a);
        if (c>a) swap(c,a);
        if (c>b) swap(c,b);
        if (y>x) swap(x,y);
        
        if (x<b) cout << -1 << endl;
        else if (x<a){
            if (y<b) cout << -1 << endl;
            else cout << next(b) << endl;
        }
        else{
            // match c and x
            if (y<b) cout << next(a) << endl;
            else if (y<a) cout << next(b) << endl;
            else cout << next(0) << endl;
        }
    }
    return 0;
}