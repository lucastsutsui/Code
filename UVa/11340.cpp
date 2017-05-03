#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, k, m, val, total;
	string text;
	char c;
	map<char,int> hash;
	
	cin >> n; //scanf("%d", &n);
	while (n--){
	    hash.clear();
	    cin >> k; //scanf("%d", &k);
	    for (int i = 0; i < k; i++){
	        cin.get(); cin >> c >> val; //scanf (" %c %d", &c, &val);
	        hash[c] = val;
	    }
	    cin >> m; //scanf("%d", &m);
	    cin.get(); //getchar();
	    total = 0;
	    while (m--){
	        getline(cin,text);
	        for (int i = 0; i < text.size(); i++) 
	            if (hash.find(text[i]) != hash.end()) total += hash[text[i]];
	    }
	    printf("%.2lf$\n", total/(double)100);
	}
	return 0;
}