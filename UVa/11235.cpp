#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int st[4*MAX];
int beg[MAX], cnt[MAX];
int n, q;

void build(int p, int l, int r){
    if (l == r) st[p] = cnt[l];
    else{
        int mid = (l+r)/2;
        build(p<<1, l, mid);
        build((p<<1)+1, mid+1, r);
        int p1 = st[p<<1], p2 = st[(p<<1)+1];
        st[p] = max(p1,p2);
    }
}

int rmq(int p, int l, int r, int i, int j){
    if (r < i || l > j) return -1;
    if (l >= i && r <= j) return st[p];
    
    int mid = (l+r)/2;
    int p1 = rmq(p<<1, l, mid, i, j);
    int p2 = rmq((p<<1)+1, mid+1, r, i, j);
    
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return max(p1,p2);
}

int query(int i, int j){
    if (beg[i] == beg[j]) return j-i+1;
    int c1 = cnt[i] + beg[i] - i;
    int c2 = j - beg[j] + 1;
    int c3 = -1;
    if (cnt[i]+beg[i] <= beg[j]-1) c3 = rmq(1, 0, n-1, cnt[i]+beg[i], beg[j]-1);
    if (c1 >= c2 && c1 >= c3) return c1;
    if (c2 >= c1 && c2 >= c3) return c2;
    return c3;
}

int main() 
{
    int num, a, b, prev;
    
    while (true){
        cin >> n;
        if (!n) break;
        cin >> q;
        
        beg[0] = 0;
        cnt[0] = 1;
        prev = 0;
        for (int i = 0; i < n; i++){
            cin >> num;
            if (i && num != prev) beg[i] = i, cnt[i] = 1;
            else if (i) beg[i] = beg[i-1], cnt[i] = cnt[i-1]+1;
            prev = num;
        }
        
        for (int i = n-2; i >= 0; i--) if (beg[i] == beg[i+1]) cnt[i] = cnt[i+1];
        
        build(1, 0, n-1); 
        for (int i = 0; i < q; i++){
            cin >> a >> b; a--; b--;
            cout << query(a,b) << '\n';
        }
    }
    return 0;
}