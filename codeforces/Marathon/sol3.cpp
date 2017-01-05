#include <bits/stdc++.h>
#define TAM 5000
#define K1 0.30
#define ATTEMPT 100
#define WRONG 2000
using namespace std;

int tested=0;
int k;
bitset<TAM+1> disc;
bitset<TAM+1> curr;
vector< pair<double,double> > prob (TAM);

void send (){
  if (tested >= ATTEMPT) return;
  tested++;
  for (int i = 0; i < TAM; i++) cout << curr[i]; cout << endl; fflush(stdout);
  cin >> k;
  disc[k-1] = 1;
  curr[k-1] = (~curr[k-1]);
}

void test (){
  // update probability
  for (int i = 0; i < k; i++){
    if (curr[i] == 0){
      prob[i].first += 20.0/(double)k;
      prob[i].second -= 20.0/(double)k;
    }
    else{
      prob[i].second += 20.0/(double)k;
      prob[i].first -= 20.0/(double)k;
    }
  }

  // generate next sequence
  if (tested < 60){
    for (int i = 0; i < k; i++) if (disc[i] == 0) curr[i] = rand()%2;
  }
  else if (tested<95){
    for (int i = 0; i < k; i++){
      if (disc[i] == 0){
	if (prob[i].first+K1 < prob[i].second) curr[i] = 0;
	else if (prob[i].first > prob[i].second+K1) curr[i] = 1;
	else curr[i] = rand()%2;
      }
    }
  }
  else{
    for (int i = 0; i < TAM; i++){
      if (disc[i] == 0){
	if (prob[i].first < prob[i].second) curr[i] = 0;
	else if (prob[i].first > prob[i].second) curr[i] = 1;
	else curr[i] = rand()%2;
      }
    }
  }
  send();
}

int main ()
{
  srand(12345);

  for (int i = 0; i < TAM; i++){
    prob[i].first = prob[i].second = 0.5;
    curr[i] = rand()%2;
    disc[i] = 0;
  }
  send ();
  
  while (tested<ATTEMPT) test();

  return 0;
}
