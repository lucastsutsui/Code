#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, m;
bool visited[MAX][MAX][4];
char tab[MAX][MAX];

typedef struct{
  int x,y,ang, dist;
}State;

char rot (char pos, int ang){
  if (ang == 0 || pos == '*' || pos == '+') return pos;

  if (pos == '|') return rot('-',ang-1);
  if (pos == '-') return rot('|',ang-1);
  if (pos == '^') return rot('>',(ang-1)%4);
  if (pos == '>') return rot('v',(ang-1)%4);
  if (pos == 'v') return rot('<',(ang-1)%4);
  if (pos == '<') return rot('^',(ang-1)%4);
  if (pos == 'L') return rot('U',(ang-1)%4);
  if (pos == 'U') return rot('R',(ang-1)%4);
  if (pos == 'R') return rot('D',(ang-1)%4);
  if (pos == 'D') return rot('L',(ang-1)%4);
}

int bfs(int xt, int yt, int xm, int ym){
  queue<State> f;
  State curr, next;

  curr.x = xt; curr.y = yt; curr.ang = 0; curr.dist=0;
  f.push(curr);
  
  while (f.size() > 0){
    curr = f.front();
    f.pop();

    if (curr.x == xm && curr.y == ym) return curr.dist;

    if (visited[curr.x][curr.y][curr.ang]) continue;
    visited[curr.x][curr.y][curr.ang] = true;
    next.dist = curr.dist+1;
    //cout << curr.x << ' ' << curr.y << endl;
    if (
	(rot(tab[curr.x][curr.y],curr.ang) == '+' || rot(tab[curr.x][curr.y],curr.ang) == '|' || rot(tab[curr.x][curr.y],curr.ang) == '^' || rot(tab[curr.x][curr.y],curr.ang) == 'L' || rot(tab[curr.x][curr.y],curr.ang) == 'R' || rot(tab[curr.x][curr.y],curr.ang) == 'D') 
	&& curr.x-1>=0 
	&& (rot(tab[curr.x-1][curr.y],curr.ang) == '+' || rot(tab[curr.x-1][curr.y],curr.ang) == '|' || rot(tab[curr.x-1][curr.y],curr.ang) == 'v' || rot(tab[curr.x-1][curr.y],curr.ang) == 'L' || rot(tab[curr.x-1][curr.y],curr.ang) == 'R' || rot(tab[curr.x-1][curr.y],curr.ang) == 'U')){
      next.x = curr.x-1; next.y = curr.y; next.ang = curr.ang;
      f.push(next);
    }
    if (
	(rot(tab[curr.x][curr.y],curr.ang) == '+' || rot(tab[curr.x][curr.y],curr.ang) == '|' || rot(tab[curr.x][curr.y],curr.ang) == 'v' || rot(tab[curr.x][curr.y],curr.ang) == 'L' || rot(tab[curr.x][curr.y],curr.ang) == 'R' || rot(tab[curr.x][curr.y],curr.ang) == 'U') 
	&& curr.x+1<n 
	&& (rot(tab[curr.x+1][curr.y],curr.ang) == '+' || rot(tab[curr.x+1][curr.y],curr.ang) == '|' || rot(tab[curr.x+1][curr.y],curr.ang) == '^' || rot(tab[curr.x+1][curr.y],curr.ang) == 'L' || rot(tab[curr.x+1][curr.y],curr.ang) == 'R' || rot(tab[curr.x+1][curr.y],curr.ang) == 'D')){
      next.x = curr.x+1; next.y = curr.y; next.ang = curr.ang;
      f.push(next);
    }
    if (
	(rot(tab[curr.x][curr.y],curr.ang) == '+' || rot(tab[curr.x][curr.y],curr.ang) == '-' || rot(tab[curr.x][curr.y],curr.ang) == '>' || rot(tab[curr.x][curr.y],curr.ang) == 'L' || rot(tab[curr.x][curr.y],curr.ang) == 'U' || rot(tab[curr.x][curr.y],curr.ang) == 'D') 
	&& curr.y+1<m 
	&& (rot(tab[curr.x][curr.y+1],curr.ang) == '+' || rot(tab[curr.x][curr.y+1],curr.ang) == '-' || rot(tab[curr.x][curr.y+1],curr.ang) == '<' || rot(tab[curr.x][curr.y+1],curr.ang) == 'U' || rot(tab[curr.x][curr.y+1],curr.ang) == 'R' || rot(tab[curr.x][curr.y+1],curr.ang) == 'D')){
      next.x = curr.x; next.y = curr.y+1; next.ang = curr.ang;
      f.push(next);
    }
    if (
	(rot(tab[curr.x][curr.y],curr.ang) == '+' || rot(tab[curr.x][curr.y],curr.ang) == '-' || rot(tab[curr.x][curr.y],curr.ang) == '<' || rot(tab[curr.x][curr.y],curr.ang) == 'U' || rot(tab[curr.x][curr.y],curr.ang) == 'R' || rot(tab[curr.x][curr.y],curr.ang) == 'D') 
	&& curr.y-1>=0 
	&& (rot(tab[curr.x][curr.y-1],curr.ang) == '+' || rot(tab[curr.x][curr.y-1],curr.ang) == '-' || rot(tab[curr.x][curr.y-1],curr.ang) == '>' || rot(tab[curr.x][curr.y-1],curr.ang) == 'L' || rot(tab[curr.x][curr.y-1],curr.ang) == 'U' || rot(tab[curr.x][curr.y-1],curr.ang) == 'D')){
      next.x = curr.x; next.y = curr.y-1; next.ang = curr.ang;
      f.push(next);
    }
  
    next.x = curr.x; next.y = curr.y; next.ang = (curr.ang+1)%4;
    f.push(next);
  }

  return -1;
}

int main ()
{
  int xt,yt,xm,ym;

  cin >> n >> m;
  
  for (int i = 0; i < n; i++){
    getchar();
    for (int j = 0; j < m; j++)
      cin >> tab[i][j];
  }

  cin >> xt >> yt;
  cin >> xm >> ym;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int a = 0; a < 4; a++)
	visited[i][j][a] = false;

  cout << bfs(xt-1,yt-1,xm-1,ym-1) << endl;

  return 0;
}
