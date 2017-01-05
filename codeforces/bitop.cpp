#include <iostream>

typedef struct cel{
  int num;
  struct cel *f1, *f2;
}celula;

using namespace std;

void constroi (celula *p, int n, int m){
  p = new celula;
  constroi (p->f1, n-1, m);
  constroi (p->f2, n-1, m);

int main ( )
{
  int n, m;
  int p, b;
  celula *p;

  cin >> n >> m;

  constroi (p, n, m);

  return 0;
}
