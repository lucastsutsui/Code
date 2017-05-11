int st[4*MAX];
int beg[MAX], cnt[MAX];

void build(int p, int l, int r){
    if (l == r) st[p] = l; // Sets the value for a leaf
    else{
        int mid = (l+r)/2;
        build(p<<1, l, mid);
        build((p<<1)+1, mid+1, r);
        int p1 = st[p<<1], p2 = st[(p<<1)+1];
        
        // Gets the value from one (best) of child nodes
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
    return max(p1,p2); // Returns value from one (best) of child nodes
}
