#include <bits/stdc++.h>
using namespace std;

bool isLeap (int n){
    return (n%4 == 0 && (n%100 != 0 || n%400 == 0));
}

int mN[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int mL[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int accN[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int accL[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

int main() 
{
    int n, d, m, y;
    while (true){
        cin >> n >> d >> m >> y;
        if (n == 0 && d == 0 && m == 0 && y == 0) break;
        
        n += d-1;
        d = 1;
        if (isLeap(y)){ n += accL[m-1]; m = 1; }
        else { n += accN[m-1]; m = 1; }
        
        while (n){
            if (isLeap(y)){
                if (n >= 366){ n -= 366; y++; }
                else if (n >= mL[m-1]){ n -= mL[m-1]; m++; }
                else { d += n; n = 0; }
            }
            else {
                if (n >= 365){ n -= 365; y++; }
                else if (n >= mN[m-1]){ n -= mN[m-1]; m++; }
                else { d += n; n = 0; }
            }
        }
        
        printf ("%d %d %d\n", d, m, y);
    }
	return 0;
}