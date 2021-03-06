void power(long long m[2][2], long long n){
    if (n == 1) return;
    long long a[2][2] = {{m[0][0], m[0][1]}, {m[1][0], m[1][1]}},a1,a2,a3,a4;
    
    power(a, n/2);
    
    a1 = ((a[0][0]*a[0][0])%b + (a[0][1]*a[1][0])%b) % b;
    a2 = ((a[0][0]*a[0][1])%b + (a[0][1]*a[1][1])%b) % b;
    a3 = ((a[1][0]*a[0][0])%b + (a[1][1]*a[1][0])%b) % b;
    a4 = ((a[1][0]*a[0][1])%b + (a[1][1]*a[1][1])%b) % b;
    
    if (n%2 == 1){
        m[0][0] = (a1 + a2)%b;
        m[0][1] = a1;
        m[1][0] = (a3 + a4)%b;
        m[1][1] = a3;
    }
    else{
        m[0][0] = a1; m[0][1] = a2; m[1][0] = a3; m[1][1] = a4;
    }
}
