#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int l, m;
queue<int> lf, rg;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int c, l, len, cont, kk;
    bool lef;
    string dir;
    cin >> c;
    while (c--){
        cin >> l >> m;
        for (int i = 0; i < m; i++){
            cin >> len >> dir;
            if (dir == "left") lf.push(len);
            else rg.push(len);
        }
        lef = true;
        cont = 0;
        while (lf.size() || rg.size()){
            int kk = 0;
            while (lef && lf.size() && lf.front()+kk <= l*100){
                kk += lf.front(); lf.pop();
            }
            while (!lef && rg.size() && rg.front()+kk <= l*100){
                kk += rg.front(); rg.pop();
            }
            cont++;
            lef = !lef;
        }
        cout << cont << el;
    }
    
    return 0;
}