#include <stdio.h>
#include <string.h>

int main ()
{
  char str[60];
  double p, total;
  int media;

  scanf ("%s", str);

  scanf ("%lf", &p);

  media = strlen(str);

  total = 0.0;
  for (int i = 0; str[i] != '\0'; i++){
    if (str[i] == '1')
      total += (double) (1.0/media);
    else if (str[i] == '?')
      total += ((double)(1.0/media)) * p;
  }

  printf ("%.5lf\n", total);

  return 0;
}
