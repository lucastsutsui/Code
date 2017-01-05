#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    int points[24], k;
    
    while(getline(cin,input)){
        if (input == "Game Over") break;
        
        k = 0;
        for (int i = 0; i < 24; i++) points[i] = 0;
        
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ') continue;
            else if (input[i] == 'X') points[k++] = 12;
            else if (input[i+2] == '/'){
                points[k++] = (input[i] - '0');
                points[k++] = 11;
                i += 2;
            }
            else {
                points[k++] = (input[i] - '0');
                if (i+2 < input.size()) points[k++] = (input[i+2] - '0');
                i += 2;
            }
        }
        
        int total = 0,rounds = 0;
        for (int i = 0; i < 24; i++){
            if (rounds == 10) break;
            
            if (points[i] < 10 && points[i+1] < 10){
                total += points[i] + points[i+1];
                i++;
            }
            else if (points[i+1] == 11){
                total += 10;
                total += (points[i+2] > 10 ? 10 : points[i+2]);
                i++;
            }
            else{
                total += 10;
                if (points[i+2] == 11) total += 10;
                else total += (points[i+1] > 10 ? 10 : points[i+1]) + (points[i+2] > 10 ? 10 : points[i+2]);
            }
            rounds++;
        }
        
        cout << total << endl;
    }
    
	return 0;
}