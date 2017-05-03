#include <bits/stdc++.h>
#define el '\n'
using namespace std;

typedef long long int lld;

lld r(lld a, lld b){
    lld c = (a+b);
    c *= 10;
    c /= 2;
    c -= c%10;
    c /= 10;
    return c;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    lld x;
    vector<lld> v;
    
    while (cin >> x){
        v.push_back(x);
        if (v.size()%2 == 1){
            nth_element(v.begin(), v.begin()+(v.size()/2), v.end());
            cout << v[v.size()/2] << el;
        }
        else{
            lld a, b;
            nth_element(v.begin(), v.begin()+(v.size()/2)-1, v.end());
            a = v[(v.size()/2)-1];
            nth_element(v.begin(), v.begin()+(v.size()/2), v.end());
            b = v[v.size()/2];
            cout << r(a,b) << el;
        }
    }
	return 0;
}