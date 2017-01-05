#include <bits/stdc++.h>
using namespace std;

bool isLeap(int y){
  return (y%400 == 0 || (y%4==0 && y%100!=0));
}

int main ()
{
  int y, next, aux;
  
  cin >> y;
  next = y+1;
  aux=1;

  if (isLeap(y)){
    if (isLeap(next)) aux++;
    while (aux%7!=0 || !isLeap(next)){
      next++;
      aux++;
      if (isLeap(next)) aux++;
      aux = aux%7;
    }
  }
  else{
    if (isLeap(next)) aux++;
    while (aux%7!=0 || isLeap(next)){
      next++;
      aux++;
      if (isLeap(next)) aux++;
      aux = aux%7;
    }
  }

  cout << next << endl;
  
  return 0;
}
