#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int main()
{   
    int a,b,nb,na,num;
    bool al[MAX], be[MAX];
    
    while (cin >> a >> b && a && b){
        na=nb=0;
        for (int i = 0; i < MAX; i++) al[i] = be[i] = false;
        
        for (int i = 0; i < a; i++){
            cin >> num;
            al[num-1]=true;
        }
        for (int i = 0; i < b; i++){
            cin >> num;
            be[num-1]=true;
        }
        
        for (int i = 0; i < MAX; i++){
            if (!al[i] && be[i]) nb++;
            else if (al[i] && !be[i]) na++;
        }
        
        cout << min(nb,na) << endl;
    }
    
    return 0;
}