#define MOD 1000000007

typedef long long int lld;

// Returns (n^x) % MOD
lld binPow(lld n, lld x) {
    lld res = 1ll;
    while (x) {
        if (x & 1) res = (res*n)%MOD;
        n = (n*n)%MOD;
        x >>= 1;
    }
    return res;
}
