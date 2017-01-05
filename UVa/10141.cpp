#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, p,test=0, r;
    string raa;
    
    while (scanf("%d %d", &n, &p)){
        getchar();
        if (!n && !p) break;
        for (int i = 0; i < n; i++) getline(cin,raa);
        double price=0.0, d;
        int mx = -1;
        string best, prop, name;
        for (int i = 0; i < p; i++){
            getline(cin, prop);   
            scanf("%lf %d", &d, &r);
            getchar();
            for (int j = 0; j < r; j++) getline(cin, name);
            if (r > mx || (r == mx && price > d)){
                mx = r;
                best = prop;
                price = d;
            } 
        }
        if (test!=0) cout << endl;
        cout << "RFP #" << ++test << endl << best << endl;
    }
    
    return 0;
}