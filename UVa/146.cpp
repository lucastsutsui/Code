#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string str;
    while (true){
        cin >> str;
        if (str.size() == 1 && str[0] == '#') break;
        if (next_permutation(str.begin(), str.end())) cout << str << "\n";
        else cout << "No Successor\n";
    }
    return 0;
}