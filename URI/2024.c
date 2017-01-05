#include <stdio.h>

void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}

int main ()
{    
    int n, v[100001][3], i;
    
    scanf ("%d", &n);
    
    for (i=0; i<n; i++){
        scanf ("%d%d%d", &v[i][0], &v[i][1], &v[i][2]);
        if (v[i][0] < v[i][1]) swap(&(v[i][0]), &(v[i][1]));
        if (v[i][0] < v[i][2]) swap(&(v[i][0]), &(v[i][2]));
        if (v[i][1] < v[i][2]) swap(&(v[i][1]), &(v[i][2]));
    }
    
    int h = 0;
    int ansa = 0, ansb = 0;
    
    for (i=n-1; i>=0; i--){
        if (v[i][2] >= ansa && v[i][1] >= ansb){
            ansa = v[i][2];
            ansb = v[i][1];
            h += v[i][0];
        }
        else if (v[i][1] >= ansa && v[i][0] >= ansb){
            ansa = v[i][1];
            ansb = v[i][0];
            h += v[i][2];
        }
        else {
            h = -1;
            break;
        }
    }
    
    printf ("%d\n", h);
    
    return 0;
}
