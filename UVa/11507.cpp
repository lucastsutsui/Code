#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int l;
    string com;
    
    while (cin >> l && l){   
        string pos = "+x";
        for (int i = 0; i < l-1; i++){
            cin >> com;
            if (com == "No") continue;
            if (pos == "+x") pos = com;
            else if (pos == "-x"){
                if (com[0] == '-') com[0] = '+';
                else com[0] = '-';
                pos = com;
            }
            else if (pos == "+y"){
                if (com == "+y") pos = "-x";
                else if (com == "-y") pos = "+x";
            }
            else if (pos == "-y"){
                if (com == "+y") pos = "+x";
                else if (com == "-y") pos = "-x";
            }
            else if (pos == "+z"){
                if (com == "+z") pos = "-x";
                else if (com == "-z") pos = "+x";
            }
            else {
                if (com == "+z") pos = "+x";
                else if (com == "-z") pos = "-x";
            }
        }
        cout << pos << endl;
    }
    
    return 0;
}