#include <bits/stdc++.h>
#define MAX 500045
using namespace std;

int matchings;

void kmpPreprocess(int P[], int m, int b[]) {
    int i = 0, j = -1; 
    b[0] = -1;
    
    while (i < m) { 
       while (j >= 0 && !(P[j] == P[i] || (P[i] != -1 && P[j] == -1 && P[i] > j))) j = b[j];
       b[++i] = ++j;
    }
}

void KMP(int P[], int T[], int m, int n) {
    int i = 0, j = 0, b[MAX];
    
    kmpPreprocess(P, m, b);
    
    while (i < n) { 
        while (j >= 0 && !(T[i] == P[j] || (P[j] == -1 && T[i] != -1 && T[i] > j))) j = b[j];
        i++; j++;
        if (j == m) { 
            matchings++;
            j = b[j]; 
        } 
    } 
}

int main()
{
    string s;
    int n, p;
    int strp[MAX], strt[MAX];
    int ult[30];
    
    cin >> s;
    cin >> n;
    
    for (int i = 0; i < 30; i++) ult[i] = -1;
    for (int i = 0; i < n; i++){
        cin >> p;
        strp[i] = (ult[p] == -1 ? -1 : (i - ult[p]));
        ult[p] = i;
    }
    
    for (int i = 0; i < 30; i++) ult[i] = -1;
    for (int i = 0; i < s.size(); i++){
        strt[i] = (ult[s[i]-'a'] == -1 ? -1 : (i - ult[s[i]-'a']));
        ult[s[i]-'a'] = i;
    }
    
    matchings = 0;
    KMP(strp, strt, n, s.size());
    cout << matchings << endl;
    
    return 0;
}
