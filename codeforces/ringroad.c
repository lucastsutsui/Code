#include <stdio.h>

int main ( )
{
  long int n, m, i, total;
  long int a, b;

  while (scanf ("%ld %ld", &n, &m) != EOF){
    total = 0;

    scanf ("%ld", &a);

    total += (a - 1);

    for (i = 1; i < m; i++){
      scanf ("%ld", &b);

      if (a <= b)
	total += b - a;
      else{
	total += n - a;
	total += b;
      }
      
      a = b;
    }
    
    printf ("%ld", total);

  }

  return 0;
}
