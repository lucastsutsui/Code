#include <stdio.h>

int main ( )
{
  char s[123];
  int n[3], i, tam;

  while (scanf ("%s", s) != EOF){
    getchar ();

    n[0] = n[1] = n[2] = tam = 0;
    
    for (i = 0; s[i] != '\0'; i++)
      if (s[i] <= '3' && s[i] >= '1'){
	tam++;
	n[s[i]-'1']++;
      }

    if (n[0] != 0){
      printf ("%c", '1');
      tam--;
      n[0]--;
    }
    else if (n[1] != 0){
      printf ("%c", '2');
      tam--;
      n[1]--;
    }
    else{
      printf ("%c", '3');
      tam--;
      n[2]--;
    }

    while (tam > 0){
      if (n[0] != 0){
	printf ("+%c", '1');
	tam--;
	n[0]--;
      }
      else if (n[1] != 0){
	printf ("+%c", '2');
	tam--;
	n[1]--;
      }
      else{
	printf ("+%c", '3');
	tam--;
	n[2]--;
      }
    }
  }

  return 0;
}
