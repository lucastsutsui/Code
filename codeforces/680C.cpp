#include <bits/stdc++.h>
#define min(a,b) (((a)<(b))? (a) : (b))
#define max(a,b) (((a)>(b))? (a) : (b))
typedef long long int lld;
typedef long long unsigned int llu;

using namespace std;

int main ()
{
  char resp[5];
  int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  char tried[101] = {0};
  int sum = 0;

  for (int i = 0; primes[i] <= 7; i++){
    printf ("%d\n", primes[i]); fflush(stdout);
    cin >> resp;
    if (strcmp(resp,"yes")==0) tried[primes[i]] = 1;
    else tried[primes[i]] = 2;
    if (tried[primes[i]] == 1) sum++;
  }

  if (sum == 1){
    int div;
    for (int i = 2; i <= 100; i++)
      if (tried[i] == 1)
	div = i;

    int ans = 0;
    while (div*primes[ans] <= 100){
      int curr = primes[ans];
      if (curr == div && curr*curr <= 100) curr = curr*curr;
      
      if (tried[curr] == 0){
	printf ("%d\n", curr); fflush(stdout);
	cin >> resp;
	if (strcmp(resp,"yes") == 0) tried[curr] = 1;
	else tried[curr] = 2;
      }
      ans++;
    }
  }

  sum = 0;

  for (int i = 2; i <= 100; i++)
    if (tried[i] == 1) sum++;

  if (sum >= 2) cout << "composite" << endl;
  else cout << "prime" << endl;
  
  return 0;
}
