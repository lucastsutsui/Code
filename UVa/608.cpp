#include <bits/stdc++.h>
#define LIGHT 2
#define HEAVY 3
using namespace std;

int main() 
{
	int n, m[150], oc[150];
	string l, r, pos;
	scanf("%d", &n);
	while (n--){
	    for (int i = 'A'; i <= 'L'; i++) oc[i] = m[i] = 0;
	    
	    for (int kk = 0; kk < 3; kk++){
    	    cin >> l >> r >> pos;
    	    for (int i = 0; i < l.size(); i++) oc[l[i]]++;
    	    for (int i = 0; i < r.size(); i++) oc[r[i]]++;
    	    
	        if (pos == "even"){
	            for (int i = 0; i < l.size(); i++) m[l[i]] = 1;
	            for (int i = 0; i < r.size(); i++) m[r[i]] = 1;
	        }
	        else if (pos == "up"){
	            for (int i = 0; i < l.size(); i++){
	                if (m[l[i]] == 0) m[l[i]] = HEAVY;
	                else if (m[l[i]] == LIGHT) m[l[i]] = 1;
	            }
	            for (int i = 0; i < r.size(); i++){
	                if (m[r[i]] == 0) m[r[i]] = LIGHT;
	                else if (m[r[i]] == HEAVY) m[r[i]] = 1;
	            }
	        }
	        else {
	            for (int i = 0; i < l.size(); i++){
	                if (m[l[i]] == 0) m[l[i]] = LIGHT;
	                else if (m[l[i]] == HEAVY) m[l[i]] = 1;
	            }
	            for (int i = 0; i < r.size(); i++){
	                if (m[r[i]] == 0) m[r[i]] = HEAVY;
	                else if (m[r[i]] == LIGHT) m[r[i]] = 1;
	            }
	        }
	    }
	    bool flag = false;
	    for (int i = 'A'; i <= 'L'; i++) if (m[i] > 1 && oc[i] > 1) {
	        printf("%c is the counterfeit coin and it is %s.\n", (char)i, (m[i] == LIGHT ? "light" : "heavy")); 
	        flag = true;
	        break;
	    }
	    if (!flag){
	        for (int i = 'A'; i <= 'L'; i++) if (m[i] > 1) {
	           printf("%c is the counterfeit coin and it is %s.\n", (char)i, (m[i] == LIGHT ? "light" : "heavy")); 
	           break;
	        }
	    }
	}
	return 0;
}