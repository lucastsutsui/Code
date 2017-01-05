#include <bits/stdc++.h>
using namespace std;

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  int v[112123];
	
  cin >> n;
	
  for (int i = 0; i < n; i++) cin >> v[i];
	
  qsort (v, n, sizeof(int), compare);
	
  int mex = 1;
  for (int i = 0; i < n; i++)
    if (v[i] >= mex) mex++;
	    
  cout << mex << endl;

  return 0;
}
