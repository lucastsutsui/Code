#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int round;
    string sol, seq;
    int alp['z'+1];
    
    while (scanf("%d", &round) && round != -1){
        getchar();
        getline(cin, sol);
        getline(cin, seq);
        
        for (int i = 'a'; i <= 'z'; i++) alp[i] = 0;
        for (int i = 0; i < sol.size(); i++) alp[sol[i]]++;
        
        int strokes = 0;
        for (int i = 0; i < seq.size() && strokes < 7; i++){
            if (alp[seq[i]] > 0) alp[seq[i]] = -1;
            else if (alp[seq[i]] == 0){ strokes++; alp[seq[i]] = -1; }
        }
        
        printf("Round %d\n", round);
        bool flag = true;
        for (int i = 'a'; i <= 'z'; i++) if (alp[i] > 0) flag = false;
        if (flag) printf("You win.\n");
        else if (strokes == 7) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    
    return 0;
}