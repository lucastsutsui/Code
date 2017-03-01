#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int h,m;
    while (true){
        scanf("%d:%d", &h, &m);
        if (h == 0 && m == 0) break;
        if (h == 12) h = 0;
        double angH = h*30.0 + (m/2.0);
        double angM = m*6.0;
        if (angM > angH) swap(angM,angH);
        printf("%.3lf\n", min(abs(angH-angM), 360.0-angH+angM));
    }
	return 0;
}