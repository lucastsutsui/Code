#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <map>
#define min(a,b) (((a)>(b)) ? (b) : (a))
#define MAX 9999
using namespace std;

int n, k;
char tab[101][101];
map<int,int> memo;

int dfs (int state){
  if (memo.find(state) != memo.end()) return memo[state];
  char i = (state&0x7F);
  char j = ((state>>7)&0x7F);
  char pow = ((state>>14)&0x0F);
  char v = ((state>>18)&0x1F);
  
  if (i == n-1 && j == n-1 && tab[i][j] == 'F') return 0;
  
  int ret, r = MAX;

  if (isdigit(tab[i][j])) ret = (int)(tab[i][j]-'0');
  else{
    if (tab[i][j] == 'P') v |= 0x01;
    else if (tab[i][j] == 'O') v |= 0x02;
    else if (tab[i][j] == 'W') v |= 0x04;
    else if (tab[i][j] == 'E') v |= 0x08;
    else if (tab[i][j] == 'R') v |= 0x10;
    ret = 0;
  }

  if (i+1 < n && tab[i+1][j] != '#'){
    int aux;
    if (v == 0x1F) aux = dfs((i+1)|(j<<7)|(k<<14));
    else if (pow>0) aux = dfs((i+1)|(j<<7)|((pow-1)<<14)|(v<<18));
    else aux = ret+dfs((i+1)|(j<<7)|(v<<18));
    r = min(aux,r);
  }

  if (j+1 < n && tab[i][j+1] != '#'){
    int aux;
    if (v == 0x1F) aux = dfs(i|((j+1)<<7)|(k<<14));
    else if (pow>0) aux = dfs(i|((j+1)<<7)|((pow-1)<<14)|(v<<18));
    else aux = ret+dfs(i|((j+1)<<7)|(v<<18));
    r = min(aux,r);
  }
 
  return (memo[state] = r);
}

int main ()
{
  int ret,i,j;
  scanf ("%d %d", &n, &k);

  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      char li = getchar();
      while (!isdigit(li) && li != '#' && li != 'P' && li != 'O' && li != 'W' && li != 'E' && li != 'R' && li != 'I' && li != 'F') li = getchar();
      tab[i][j] = li;
    }
  }
  ret = dfs(0);
  if (ret >= MAX) puts("-1");
  else printf("%d\n", ret+1);

  return 0;
}