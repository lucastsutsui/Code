int p[MAX], r[MAX];

int find(int a){
    return (p[a] == a) ? a : (p[a] = find(p[a]));
}

void unite(int a, int b){
    int x = find(a), y = find(b);
    if (x == y) return;
    if (r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
    }
}
