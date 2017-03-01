#include <bits/stdc++.h>
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main() 
{
	int t, test=0, tam;
	string set, str;
	vector<string> v;
	bool flag;
	
	scanf ("%d", &t);
	getchar();
	while (t--){
	    set.clear(); v.clear(); str.clear();
	    getline(cin,set);
        forn(i,set.size()){
            if (set[i] != ' ' && set[i] != '.' && set[i] != ',' && set[i] != '!' && set[i] != '?' && set[i] != '(' && set[i] != ')')
                str.push_back(set[i]);
        }
        //cout << str << endl;
        tam = sqrt(str.size()); flag = true;
        if (tam*tam != str.size()) flag = false;
        else{
            v.clear();
            forn(i,tam){ 
                string aux;
                forn(j,tam)
                    aux.push_back(str[(i*tam)+j]);
                v.push_back(aux);
            }
            forn(i,tam) forn(j,tam) if (v[i][j] != str[(i*tam)+j]) flag = false;
            forn(i,tam) forn(j,tam) if (v[j][i] != str[(i*tam)+j]) flag = false;
            forn(i,tam) forn(j,tam) if (v[tam-i-1][tam-j-1] != str[(i*tam)+j]) flag = false;
            forn(i,tam) forn(j,tam) if (v[tam-j-1][tam-i-1] != str[(i*tam)+j]) flag = false;
        }
	    printf ("Case #%d:\n", ++test);
	    if (flag) printf ("%d\n", tam);
	    else puts("No magic :(");
	}
	
	return 0;
}