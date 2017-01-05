#include <bits/stdc++.h>
using namespace std;

int toI(char x){
    if (x >= '2' && x <= '9') return x-'0';
    return 10;
}

int main()
{
    int n, t, y;
    string hand;
    char cards[53][2];
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; i++){ 
        getline(cin,hand);
        reverse(hand.begin(),hand.end());
        t=y=0;
        for (int i = 0; i < hand.size(); i++){
            if (hand[i] == ' ') continue;
            if (t < 25 || y != 0){
                cards[t][1] = hand[i];
                cards[t][0] = hand[i+1];
                t++;
                i++;
            }
            else{
                for (int j = 0; j < 3; j++){
                    int x = toI(hand[i+1]);
                    y+=x;
                    i+=3;
                    for (int k = 0; k < 10-x; k++) i+=3;
                }
                i--;
            }
        }        
        printf ("Case %d: %c%c\n", i+1, cards[t-y][0], cards[t-y][1]);
    }
    
    return 0;
}