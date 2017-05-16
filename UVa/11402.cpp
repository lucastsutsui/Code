#include <bits/stdc++.h>
#define MAX 1100000
using namespace std;

bitset<MAX> v;
int st[4*MAX];
int lazy[4*MAX];
int n, q;

void build(int p, int l, int r){
    if (l == r){ st[p] = (v[l] == 1 ? 1 : 0); lazy[p] = -1; }
    else{
        int mid = (l+r)/2;
        build(p<<1, l, mid);
        build((p<<1)+1, mid+1, r);
        int p1 = st[p<<1], p2 = st[(p<<1)+1];
        st[p] = p1+p2;
        lazy[p] = -1;
    }
}

int upd(int state, int next){
    if (state == -1) return next;
    if (state == 0) return (next == 0 ? -1 : next);
    if (state == 1) return (next == 0 ? 2 : next);
    else return (next == 0 ? 1 : next);
}

int rmq(int p, int l, int r, int i, int j){
    if (r < i || l > j) return -1;
    
    if (lazy[p] != -1){
        if (lazy[p] == 0) st[p] = (r-l+1) - st[p];
        else if (lazy[p] == 1) st[p] = (r-l+1);
        else st[p] = 0;
        
        lazy[p<<1] = upd(lazy[p<<1], lazy[p]);
        lazy[(p<<1)+1] = upd(lazy[(p<<1)+1], lazy[p]);
        
        lazy[p] = -1;
    }
    
    if (l >= i && r <= j) return st[p];
    
    int mid = (l+r)/2;
    int p1 = rmq(p<<1, l, mid, i, j);
    int p2 = rmq((p<<1)+1, mid+1, r, i, j);
    
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1+p2;
}

void update(int p, int l, int r, int i, int j, char op){
    if (lazy[p] != -1){
        if (lazy[p] == 0) st[p] = (r-l+1) - st[p];
        else if (lazy[p] == 1) st[p] = (r-l+1);
        else st[p] = 0;
        
        lazy[p<<1] = upd(lazy[p<<1], lazy[p]);
        lazy[(p<<1)+1] = upd(lazy[(p<<1)+1], lazy[p]);
        
        lazy[p] = -1;
    }
    
    if (r < i || l > j) return;
    if (l >= i && r <= j){
        if (op) st[p] = (op == 1 ? (r-l+1) : 0);
        else st[p] = (r-l+1) - st[p];
        
        if (r != l){
            lazy[p<<1] = upd(lazy[p<<1], op);
            lazy[(p<<1)+1] = upd(lazy[(p<<1)+1], op);
        }
        
        return;
    }
    
    int mid = (l+r)/2;
    update(p<<1, l, mid, i, j, op);
    update((p<<1)+1, mid+1, r, i, j, op);
    st[p] = st[p<<1]+st[(p<<1)+1];
}

int main() 
{
    int test;
    int m, t, n, q, a, b;
    string pir, op;
    
    cin >> test;
    
    for (int tt = 1; tt <= test; tt++){
        n = 0;
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> t;
            cin >> pir;
            for (int j = 0; j < t; j++) for (int k = 0; k < pir.size(); k++) v[n++] = (pir[k] == '0' ? 0 : 1);
        }
        build(1,0,n-1);
        cout << "Case " << tt << ":\n";
        cin >> q;
        int que = 1;
        for (int i = 0; i < q; i++){
            cin >> op >> a >> b;
            if (op == "S") cout << "Q" << que++ << ": " << rmq(1,0,n-1,a,b) << '\n';
            else if (op == "I") update(1,0,n-1,a,b,0);
            else if (op == "F") update(1,0,n-1,a,b,1);
            else update(1,0,n-1,a,b,2);
        }
    }
    return 0;
}