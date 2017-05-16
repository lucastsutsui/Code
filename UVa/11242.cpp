#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int f, r, fp[15], rp[15];
    vector<double> ratios;
    double spread;
    cout << fixed << setprecision(2);
    
    while (cin >> f && f){
        cin >> r;
        for (int i = 0; i < f; i++) cin >> fp[i];
        for (int i = 0; i < r; i++) cin >> rp[i];
        
        ratios.clear();
        for (int i = 0; i < f; i++)
            for (int j = 0; j < r; j++) ratios.push_back(rp[j]/(double)fp[i]);
            
        sort(ratios.begin(), ratios.end());
        spread = 0.0;
        
        for (int i = 0; i < ratios.size()-1; i++)
            spread = max(ratios[i+1]/ratios[i], spread);
            
        cout << spread << '\n';
    }
    
	return 0;
}