#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, b, sg, sb, num;
    multiset<int> blue, green;
    multiset<int>::iterator it;
    vector<int> a1, a2;
    
    cin >> n;
    while (n--){
        cin >> b >> sg >> sb;
        blue.clear(); green.clear();
        
        for (int i = 0; i < sg; i++){
            cin >> num; green.insert(num);
        }
        for (int i = 0; i < sb; i++){
            cin >> num; blue.insert(num);
        }
        
        while (blue.size() && green.size()){
            int m = min(b, (int)min(green.size(), blue.size()));
            a1.clear(); a2.clear();
            
            for (int i = 0; i < m; i++){
                it = green.end(); it--;
                a1.pb(*it);
                green.erase(it);
            }            
            for (int i = 0; i < m; i++){
                it = blue.end(); it--;
                a2.pb(*it);
                blue.erase(it);
            }
            for (int i = 0; i < m; i++){
                if (a1[i] == a2[i]) continue;
                else if (a1[i] > a2[i]) green.insert(a1[i]-a2[i]);
                else blue.insert(a2[i]-a1[i]);
            }
        }
        
        if (blue.size()){
            cout << "blue wins\n";
            while (blue.size()){
                it = blue.end(); it--;
                cout << *(it) << '\n';
                blue.erase(it);
            }
        }
        else if (green.size()){
            cout << "green wins\n";
            while (green.size()){
                it = green.end(); it--;
                cout << *(it) << '\n';
                green.erase(it);
            }
        }
        else cout << "green and blue died\n";
        if (n) cout << '\n';
    }
    
    return 0;
}