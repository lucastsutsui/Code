#include <bits/stdc++.h>
#define mi(a,b) mirror[a]=b
using namespace std;

string input;
int mirror['Z'+1];

bool checkp(){
    for (int i = 0; i < input.size()/2; i++)
        if (input[i] != input[input.size()-1-i]) return false;
    return true;
}

bool checkm(){
    for (int i = 0; i < (1+input.size())/2; i++){
        int j = input.size()-1-i;
        if (mirror[input[i]] == -1 || mirror[input[j]] == -1) return false;
        else if (mirror[input[i]] != input[j] && mirror[input[j]] != input[i]) return false;
    }
    return true;
}

int main() {
    for (int i = '1'; i <= 'Z'; i++) mirror[i] = -1;
    mi('A','A'); mi('E','3'); mi('H','H'); mi('I','I'); mi('J','L'); mi('L','J'); mi('M','M');
    mi('O','O'); mi('S','2'); mi('T','T'); mi('U','U'); mi('V','V'); mi('W','W'); mi('X','X');
    mi('Y','Y'); mi('Z','5'); mi('1','1'); mi('2','S'); mi('3','E'); mi('5','Z'); mi('8','8');
    
    while (getline(cin,input)){
        bool palind = checkp();
        bool mirr = checkm();
        if (palind && mirr) printf("%s -- is a mirrored palindrome.\n\n", input.c_str());
        else if (mirr) printf ("%s -- is a mirrored string.\n\n", input.c_str());
        else if (palind) printf ("%s -- is a regular palindrome.\n\n", input.c_str());
        else printf ("%s -- is not a palindrome.\n\n", input.c_str());
    }
	return 0;
}