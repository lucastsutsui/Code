#include <bits/stdc++.h>
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

bool cmp (char a, char b){
    return toupper(a) < toupper(b);
}

bool compare(string a, string b){
    forn(i,a.size()) if (toupper(a[i]) != toupper(b[i])) return false;
    return true;
}

int main() 
{
	string str, aux;
	vector<string> w, dic;
	
	while (true){
	    getline(cin, str);
	    if (str.size() == 1 && str[0] == '#') break;
	    forn(i,str.size()){
	        if(str[i] == ' ' && aux.size()){
	            dic.push_back(aux); 
	            aux.clear();
	        }
	        else if (str[i] != ' ') aux.push_back(str[i]);
	    }
	    if (aux.size()) dic.push_back(aux);
	    aux.clear();
	}
	
	sort(dic.begin(), dic.end());
	w.assign(dic.begin(), dic.end());
	forn(i,w.size()) sort(w[i].begin(), w[i].end(), cmp);
	    
    forn(i,w.size()){
        if (w[i].size() == 0) continue;
        bool flag = true;
        for (int j = i+1; j < w.size(); j++){
            if (w[j].size() == w[i].size() && compare(w[i],w[j])){
                w[j].clear();
                flag = false;
            }
        }
        if (flag) cout << dic[i] << endl;
    }
    
	return 0;
}