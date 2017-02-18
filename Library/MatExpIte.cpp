void mul(lld a[2][2], lld c[2][2]) {
	lld res[2][2];
	forn(i, 2)
		forn(j, 2) {
			res[i][j] = 0;
			forn(k, 2) res[i][j] += ((a[i][k]%b)*(c[k][j]%b))%b;
		}
	forn(i, 2) forn(j, 2) a[i][j] = res[i][j];
}

void binpow(lld a[2][2], lld n) {
	lld res[2][2] = {{1,0},{0,1}};

	while (n) {
		if (n & 1) mul(res, a);
		mul(a, a);
		n >>= 1;
	}

	forn(i,2) forn(j,2) a[i][j] = res[i][j];
}
