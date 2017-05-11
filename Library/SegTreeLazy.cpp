// Segment Tree implementation with Lazy Propagation

int st[4*MAX];
int lazy[4*MAX];

void build(int p, int l, int r){
    if (l == r){ st[p] = 1; lazy[p] = -1; }
    else{
        int mid = (l+r)/2;
        build(p<<1, l, mid);
        build((p<<1)+1, mid+1, r);
        int p1 = st[p<<1], p2 = st[(p<<1)+1];
        st[p] = p1+p2;
        lazy[p] = -1;
    }
}

// Returns the result from changing a lazy node from state (state) to state (next)
int upd(int state, int next){
    if (state == -1) return next;
    if (state == 0) return (next == 0 ? -1 : next);
    if (state == 1) return (next == 0 ? 2 : next);
    else return (next == 0 ? 1 : next);
}

int query(int p, int l, int r, int i, int j){
    if (r < i || l > j) return -1;
    
    if (lazy[p] != -1){
        // Updates the current node of Segment Tree
        if (lazy[p] == 0) st[p] = (r-l+1) - st[p];
        else if (lazy[p] == 1) st[p] = (r-l+1);
        else st[p] = 0;
        
        // Updates states of left and right lazy nodes
        lazy[p<<1] = upd(lazy[p<<1], lazy[p]);
        lazy[(p<<1)+1] = upd(lazy[(p<<1)+1], lazy[p]);
        
        // Updates state of current lazy node
        lazy[p] = -1;
    }
    
    if (l >= i && r <= j) return st[p];
    
    int mid = (l+r)/2;
    int p1 = query(p<<1, l, mid, i, j);
    int p2 = query((p<<1)+1, mid+1, r, i, j);
    
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1+p2;
}

void update(int p, int l, int r, int i, int j, char op){
    if (lazy[p] != -1){
        // Updates the current node of Segment Tree
        if (lazy[p] == 0) st[p] = (r-l+1) - st[p];
        else if (lazy[p] == 1) st[p] = (r-l+1);
        else st[p] = 0;
        
        // Updates states of left and right lazy nodes
        lazy[p<<1] = upd(lazy[p<<1], lazy[p]);
        lazy[(p<<1)+1] = upd(lazy[(p<<1)+1], lazy[p]);
        
        // Updates state of current lazy node
        lazy[p] = -1;
    }
    
    if (r < i || l > j) return;
    if (l >= i && r <= j){
        // Updates the current node of Segment Tree (according to op)
        if (op) st[p] = (op == 1 ? (r-l+1) : 0);
        else st[p] = (r-l+1) - st[p];
        
        if (r != l){
            // Updates states of left and right lazy nodes (according to op)
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
