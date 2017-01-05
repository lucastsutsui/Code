#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<x<<endl;

int suit(char x){
    if (x == 'S') return 0;
    if (x == 'H') return 1;
    if (x == 'D') return 2;
    return 3;
}

int rak(char x){
    if (x == 'A') return 0;
    if (x == 'T') return 9;
    if (x == 'J') return 10;
    if (x == 'Q') return 11;
    if (x == 'K') return 12;
    return (x-'1');
}

bool stopped(int cards[4][13], int s[]){
    for (int i = 0; i < 4; i++)
        if (cards[i][0] == 0 && (cards[i][12] == 0 || s[i] == 1) && 
        (cards[i][11] == 0 || s[i] <= 2)) return false;
    return true;
}

int main ()
{
    string hand;
    int cards[4][13];
    int points, points2, s[4];
    
    while (getline(cin,hand)){
        for (int i = 0; i < 13; i++) 
            cards[0][i] = cards[1][i] = cards[2][i] = cards[3][i] = 0;
        s[0] = s[1] = s[2] = s[3] = 0;
        for (int i = 0; i < hand.size(); i++){
            if (hand[i] == ' ') continue;
            cards[suit(hand[i+1])][rak(hand[i])] = 1;
            s[suit(hand[i+1])]++;
            i++;
        }
        points = 0;
        
        // rule 1
        points += 4*(cards[0][0]+cards[1][0]+cards[2][0]+cards[3][0]);
        points += 3*(cards[0][12]+cards[1][12]+cards[2][12]+cards[3][12]);
        points += 2*(cards[0][11]+cards[1][11]+cards[2][11]+cards[3][11]);
        points += (cards[0][10]+cards[1][10]+cards[2][10]+cards[3][10]);
        // rule 2
        points -= (cards[0][12] && s[0] == 1)+(cards[1][12] && s[1] == 1)+
        (cards[2][12] && s[2] == 1)+(cards[3][12] && s[3] == 1);
        // rule 3
        points -= (cards[0][11] && s[0] <= 2)+(cards[1][11] && s[1] <= 2)+
        (cards[2][11] && s[2] <= 2)+(cards[3][11] && s[3] <= 2);
        // rule 4
        points -= (cards[0][10] && s[0] <= 3)+(cards[1][10] && s[1] <= 3)+
        (cards[2][10] && s[2] <= 3)+(cards[3][10] && s[3] <= 3);
        
        points2 = points;
        // rule 5
        points += (s[0]==2) + (s[1]==2) + (s[2]==2) + (s[3]==2);
        // rule 6
        points += 2*(s[0]==1) + 2*(s[1]==1) + 2*(s[2]==1) + 2*(s[3]==1);
        // rule 7
        points += 2*(s[0]==0) + 2*(s[1]==0) + 2*(s[2]==0) + 2*(s[3]==0);
        
        if (points < 14) cout << "PASS\n";
        else if (points2 >= 16 && stopped(cards,s)) cout << "BID NO-TRUMP\n";
        else{
            cout << "BID ";
            int mx = max(s[0],max(s[1],max(s[2],s[3])));
            if (mx == s[0]) cout << 'S';
            else if (mx == s[1]) cout << 'H';
            else if (mx == s[2]) cout << 'D';
            else if (mx == s[3]) cout << 'C';
            cout << "\n";
        }
    }
    return 0;
}