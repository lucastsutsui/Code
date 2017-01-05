#include <bits/stdc++.h>
using namespace std;

char toH(char c){
    if (c <= 9) return ('0'+c);
    return ('A'+c-10);
}

int main ()
{
    int t;
    string com;
    bool prim;
    scanf ("%d\n", &t); 
    for (int i = 0; i < t; i++){
        getline(cin, com);   
        char mem[100] = {0};
        int point = 0;
        prim = true;
        printf("Case %d:", i+1);
        for (int j = 0; j < com.size(); j++){
            if (com[j] == '>') point=(point+1)%100;
            else if (com[j] == '<') point=(point-1+100)%100;
            else if (com[j] == '+') mem[point] = (mem[point]+1)%256;
            else if (com[j] == '-') mem[point] = (mem[point]-1+256)%256;
        }
        for (int j = 0; j < 100; j++)
            printf(" %c%c", toH((mem[j]&0xF0)>>4), toH(mem[j]&0x0F));
        printf("\n");
    }
    
    return 0;
}