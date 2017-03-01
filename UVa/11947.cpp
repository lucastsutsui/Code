#include <bits/stdc++.h>
using namespace std;

bool isLeap (int n){
    return (n%4 == 0 && (n%100 != 0 || n%400 == 0));
}

int mN[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int mL[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int accN[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int accL[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

void nDaysAfter (int n, int &d, int &m, int &y){
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
}

string sign(int d, int m){
    if ((m == 1 && d >= 21) || (m == 2 && d <= 19)) return "aquarius";
    if ((m == 2 && d >= 20) || (m == 3 && d <= 20)) return "pisces";
    if ((m == 3 && d >= 21) || (m == 4 && d <= 20)) return "aries";
    if ((m == 4 && d >= 21) || (m == 5 && d <= 21)) return "taurus";
    if ((m == 5 && d >= 22) || (m == 6 && d <= 21)) return "gemini";
    if ((m == 6 && d >= 22) || (m == 7 && d <= 22)) return "cancer";
    if ((m == 7 && d >= 23) || (m == 8 && d <= 21)) return "leo";
    if ((m == 8 && d >= 22) || (m == 9 && d <= 23)) return "virgo";
    if ((m == 9 && d >= 24) || (m == 10 && d <= 23)) return "libra";
    if ((m == 10 && d >= 24) || (m == 11 && d <= 22)) return "scorpio";
    if ((m == 11 && d >= 23) || (m == 12 && d <= 22)) return "sagittarius";
    if ((m == 12 && d >= 23) || (m == 1 && d <= 20)) return "capricorn";
}

int main() 
{
    int n, d, m, y, t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++){
        scanf("%d", &n);
        
        y = n%10000;
        n /= 10000;
        d = n%100;
        n /= 100;
        m = n;
        
        nDaysAfter(40*7, d, m, y);
        
        printf ("%d %.2d/%.2d/%.4d %s\n", test, m, d, y, sign(d,m).c_str());
    }
	return 0;
}