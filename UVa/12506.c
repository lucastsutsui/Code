/*
 * Shortest Names
 */

#include <stdio.h>

typedef struct cel{
  char s[1000];
  struct cel p[1000];
}arvore;

void insere (arvore *v, char *str){
  int i = 0, j;
  
  while (str[i] != '\0'){
    j = 0;
    
    while (v->s[j] != '\0' && v->s[j] != str[i]) j++;

    if (v->s[j] == '\0'){
      v->s[j] = str[i];
      v->s[j+1] = '\0';
      v->p[j] = (arvore *) malloc (sizeof (arvore));
      v = v->p[j];
      v->s[0] = '\0';
      v->p[0] = NULL;
    }
    else
      v = v->p[j];
      
    i++;
  }
}

int arruma (arvore *v){
  int aux;

  if (v->p[0] == NULL)
    return 1;  
  
  for (i = 0; v->p[i] != NULL; i++);

  if (i == 1)
    return arruma(v->p[0]);

  for (i = 0; v->p[i] != NULL; i++){
    aux = arruma(v->p[i]);
    if (aux == 1){
      free (v->p[i]);
      v->p[i] = NULL;
    }
  }
  
  return 0;
}
    

int conta (arvore *v, int c){
  int cont, i;
  
  if (v->p[0] == NULL) return 0;
  
  for (i = 0; v->p[i] != NULL; i++);
  
  if (i == 1){
    while (v->p[0] != NULL && v->p[1] == NULL){
      v = v->p[0];
      c++;
    }
    
    if (v->p[0] == NULL)
      return 0;
    return conta (v, c);
  }
  
}

int constroi_arvore (int n){
  int i, j, k;
  char str[1123123];
  
  arvore *v = (arvore *) malloc (sizeof (arvore));
  arvore->p[0] = NULL;
  arvore->s[0] = '\0';

  for (i = 0; i < n; i++){
    scanf ("%s", str);
    
    insere (v, str);
  }

  arruma (v);
  
  return conta (v, 0);
}

int main ( )
{
  int t, n;

  scanf ("%d", &t);
  
  while (t--){
    scanf ("%d", &n);
    getchar ();

    constroi_arvore (n);
  }
  
  return 0;
}
