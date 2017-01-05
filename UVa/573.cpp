#include <bits/stdc++.h>
using namespace std;

int main ()
{
    double h,u,d,f;
    
    while (cin >> h >> u >> d >> f){
        if (!h) break;
        double curr = 0;
        int day=0;
        f = u*((double)f/100.0);
        while (curr >= 0 && curr <= h){
            day++;
            if (u>0) curr += u;
            if (curr > h) break;
            curr -= d;
            u -= f;
        }
        if (curr >= h) cout << "success on day " << day << endl;
        else cout << "failure on day " << day << endl;
    }
    
    return 0;
}