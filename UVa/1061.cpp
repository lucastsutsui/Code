#include <bits/stdc++.h>
using namespace std;

int tf(string a){
    if (a == "A+") return 0;
    if (a == "A-") return 1;
    if (a == "B+") return 2;
    if (a == "B-") return 3;
    if (a == "O+") return 4;
    if (a == "O-") return 5;
    if (a == "AB+") return 6;
    return 7;
}
string ft(int a){
    if (a == 0) return "A+";
    if (a == 1) return "A-";
    if (a == 2) return "B+";
    if (a == 3) return "B-";
    if (a == 4) return "O+";
    if (a == 5) return "O-";
    if (a == 6) return "AB+";
    return "AB-";
}
bool checkRh(int a, int b, int c){
    if (c%2 == 1) return true;
    return (a%2 == 0 || b%2 == 0);
}
bool checkAbo(int a, int b, int c){
    if (c <= 1) return (a <= 1 || b <= 1 || a >= 6 || b >= 6);
    if (c <= 3) return (a/2 == 1 || b/2 == 1 || a >= 6 || b >= 6);
    if (c <= 5) return (a < 6 && b < 6);
    return ((a <= 1 && b/2 == 1) || (b <= 1 && a/2 == 1) || (a >= 6 && b <= 3) || (b >= 6 && a <= 3) || a >= 6 && b >= 6);
}
bool check(int p1, int p2, int c){
    return checkRh(p1,p2,c) && checkAbo(p1,p2,c);
}

int main() 
{
    int test=1;
	string p1, p2, c;
	while (true){
	    cin >> p1 >> p2 >> c;
	    if (p1 == "E" && p2 == "N" && c == "D") break;
	    cout << "Case " << test++ << ": ";
	    if (c == "?"){
	        int a = tf(p1), b = tf(p2);
	        cout << p1 << ' ' << p2 << ' ';
	        bool prim = true;
	        vector<int> v;
	        for(int i = 0; i < 8; i++) if (check(a,b,i)) v.push_back(i);
	        if (v.size() == 0){ cout << "IMPOSSIBLE" << endl; continue; }
	        if (v.size() == 1){ cout << ft(v[0]) << endl; continue; }
	        cout << "{" << ft(v[0]);
	        for (int i = 1; i < v.size(); i++) cout << ", " << ft(v[i]);
	        cout << "}" << endl;
	    }
	    else if (p1 == "?"){
	        int a = tf(p2), b = tf(c);
            bool prim = true;
            vector<int> v;
	        for(int i = 0; i < 8; i++) if (check(i,a,b)) v.push_back(i);
	        if (v.size() == 0){ cout << "IMPOSSIBLE " << p2 << ' ' << c << endl; continue; }
	        if (v.size() == 1){ cout << ft(v[0]) << ' ' << p2 << ' ' << c << endl; continue; }
	        cout << "{" << ft(v[0]);
	        for (int i = 1; i < v.size(); i++) cout << ", " << ft(v[i]);
	        cout << "} " << p2 << ' ' << c << endl;
	    }
	    else{
            int a = tf(p1), b = tf(c);
	        cout << p1 << ' ';
            bool prim = true;
            vector<int> v;
	        for(int i = 0; i < 8; i++) if (check(a,i,b)) v.push_back(i);
	        if (v.size() == 0){ cout << "IMPOSSIBLE " << c << endl; continue; }
	        if (v.size() == 1){ cout << ft(v[0]) << ' ' << c << endl; continue; }
	        cout << "{" << ft(v[0]);
	        for (int i = 1; i < v.size(); i++) cout << ", " << ft(v[i]);
	        cout << "} " << c << endl;
	    }
	}
	return 0;
}