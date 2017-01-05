#include <stdio.h>
#include <math.h>

void init(double v[]){
    int i;
    v[0] = log(1);
    v[1] = log(1);
    for (i = 2; i <= 10002; i++)
        v[i] = v[i-1] + log(i);
}
    

int main ()
{
    int n, a, b, c, i;
    int v1=0, v2=0;
    double fat[11234];
    char res[1123];
    
    init(fat);
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf("%d^%d", &a, &b);
        scanf ("%d!", &c);
        
        double n1 = (double)log(a)*(double)b;
        if (n1 > fat[c]){
            res[i] = 1;
            v1++;
        }
        else{
            res[i] = 2;
            v2++;
        }        
    }
    
    if (v1>v2) printf ("Campeao: Lucas!\n");
    else if (v2>v1) printf ("Campeao: Pedro!\n");
    else printf ("A competicao terminou empatada!\n");
    for (i = 0; i < n; i++){
        if (res[i] == 1) printf ("Rodada #%d: Lucas foi o vencedor\n", i+1);
        else printf ("Rodada #%d: Pedro foi o vencedor\n", i+1);
    }
    
    return 0;
}
