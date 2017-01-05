#include <bits/stdc++.h>
using namespace std;

int compare (const void *a, const void *b){
  return (*(int*)a-*(int*)b);
}

int main ()
{
  int t[101]={0};
  int num, sum=0, min;

  for (int i = 0; i < 5; i++){
    cin >> num;
    t[num]++;
    sum += num;
  }

  min = sum;
  for (int i = 100; i >= 1; i--){
    if (t[i] == 2 && min > sum-(2*i))
      min = sum - (2*i);
    else if (t[i] >= 3 && min > sum-(3*i))
      min = sum - (3*i);
  }

  cout << min << endl;

  return 0;
}
