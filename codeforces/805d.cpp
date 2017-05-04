#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long fa(int base, int exp)
{
    if(exp==1) return base;
    else
    {
        if(exp%2 == 0)
        {
            long long base1 = pow(fa(base, exp/2),2);
            if(base1 >= MOD) return base1%MOD;
            else return base1;
        }
        else
        {
            long long ans = (base*  pow(fa(base,(exp-1)/2),2));
            if(ans >= MOD) return ans%MOD;
            else return ans;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    int cont = 0;
    
    cin >> str;
    
    int conta = (str[0] == 'a' ? 1 : 0);
    for (int i = 1; i < str.size(); i++){
        if (str[i] == 'b' && conta) cont = (cont+(fa(2,conta)-1))%MOD;
        else if (str[i] == 'a') conta++;
    }
    
    cout << cont%MOD << endl;
    
    return 0;
}