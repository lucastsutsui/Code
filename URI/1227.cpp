#include <bits/stdc++.h>
#define el '\n'
#define forn(a,b) for(int (a)=0;(a)<(b);(a)++)
using namespace std;

int n, a, b, c;
double mat[101][101];
int qadj[101];

void mul(double a[101][101], double c[101][101]) {
	double res[101][101];
	forn(i, n) forn(j, n) {
			res[i][j] = 0;
			forn(k, n) res[i][j] += a[i][k]*c[k][j];
		}
	forn(i, n) forn(j, n) a[i][j] = res[i][j];
}

double solve() {
    forn(i,n){
        if (i == b-1 || i == c-1){
            forn(j,n) mat[i][j] = 0;
            mat[i][i] = 1.0;
            continue;
        }
        forn(j,n){
            if (mat[i][j] == 1.0){
                mat[i][j] = 1.0 / (double) qadj[i];
            }
        }
    }
    
	double res[101][101] = {0};
	int x = 10000;
	
	forn(i,n) res[i][i] = 1;

	while (x) {
		if (x & 1) mul(res, mat);
		mul(mat, mat);
		x >>= 1;
	}

	forn(i,n) forn(j,n) mat[i][j] = res[i][j];
	
	return mat[a-1][b-1];
}

int main() 
{
    int x,y;
    
    while (scanf("%d %d %d %d", &n, &a, &b, &c) != EOF){
        forn(i,n) forn(j,n){ mat[i][j] = 0.0; qadj[i] = 0; }
        forn(i,n-1){
            scanf("%d %d", &x, &y); x--; y--;
            mat[x][y] = mat[y][x] = 1;
            qadj[x]++; qadj[y]++;
        }
        printf("%.6lf\n", solve());
    }
    
    return 0;
}