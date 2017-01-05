#include <bits/stdc++.h>
using namespace std;

string input, proc;

bool checkp(){
    for (int i = 0; i < input.size()/2; i++)
        if (input[i] != input[input.size()-1-i]) return false;
    return true;
}

int main() {
    while (getline(cin,input)){
        if (input == "DONE") break;
        proc.clear();
        for (int i =  0; i < input.size(); i++){
            if (isalpha(input[i]) && toupper(input[i]) >= 'A' && toupper(input[i]) <= 'Z') proc.push_back(toupper(input[i]));
        }
        swap(proc,input);
        if (checkp()) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
	return 0;
}