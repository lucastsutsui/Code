#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int v[MAX];
int st[4*MAX];

void build(int p, int l, int r){
    if (l == r){ 
        if (v[l] == 0) st[p] = 0;
        else if (v[l] < 0) st[p] = -1;
        else st[p] = 1;
    }
    else{
        int mid = (l+r)/2;
        build(p<<1, l, mid);
        build((p<<1)+1, mid+1, r);
        int p1 = st[p<<1], p2 = st[(p<<1)+1];
        st[p] = p1*p2;
    }
}

int query(int p, int l, int r, int i, int j){
    if (r < i || l > j) return -1001;
    
    if (l >= i && r <= j) return st[p];
    
    int mid = (l+r)/2;
    int p1 = query(p<<1, l, mid, i, j);
    int p2 = query((p<<1)+1, mid+1, r, i, j);
    
    if (p1 == -1001) return p2;
    if (p2 == -1001) return p1;
    return p1*p2;
}

void update(int p, int l, int r, int i, int val){
    if (r < i || l > i) return;
    if (l == i && r == i){
        if (val == 0) st[p] = 0;
        else if (val > 0) st[p] = 1;
        else st[p] = -1;
        return;
    }
    
    int mid = (l+r)/2;
    update(p<<1, l, mid, i, val);
    update((p<<1)+1, mid+1, r, i, val);
    st[p] = st[p<<1]*st[(p<<1)+1];
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, a, b;
    string op;
    
    while (cin >> n >> k){
        for (int i = 0; i < n; i++) cin >> v[i];
        build(1,0,n-1);
        for (int i = 0; i < k; i++){
            cin >> op >> a >> b; a--; b--;
            if (op == "C") update(1,0,n-1,a,b+1);
            else{
                int ans = query(1,0,n-1,a,b);
                if (ans == 0) cout << '0';
                else if (ans > 0) cout << '+';
                else cout << '-';
            }
        }    
        cout << '\n';
    }
    
    return 0;
}