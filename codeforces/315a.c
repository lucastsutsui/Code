#include <stdio.h>

int main ()
{
  int n, i, b[123], a[123], soma, ai, bi, j;
  
  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    scanf ("%d %d", &a[i], &b[i]);

  for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
	if (a[j] == b[i] && j != i)
	  a[j] = -1;

  soma = 0;
  
  for (i = 0; i < n; i++)
    if (a[i] > 0) soma++;

  printf ("%d\n", soma);

  return 0;
}
