#include <bits/stdc++.h>
#define TAM 5000
#define ND 1000
#define ATTEMPT 100
#define WRONG 2000
using namespace std;

typedef pair<int,int> ii;
int tested=0;
int k;
bitset<TAM+1> disc;
bitset<TAM+1> curr;

bool myfunction (ii i,ii j) { return (i.second<j.second); }

void send (){
  if (tested >= ATTEMPT) return;
  tested++;
  for (int i = 0; i < TAM; i++) cout << curr[i]; cout << endl; fflush(stdout);
  cin >> k;
  disc[k-1] = 1;
  curr[k-1] = (~curr[k-1]);
}

void test (){
  vector<ii> v;
  vector<ii> v1;
  
  for (int i = 0; i < 4000; i+=50){
      int ant = k;
      for (int j = i; j < i+50; j++) curr[j] = (~curr[j]);
      send();
      if (k < ant) for (int j = i; j < i+50; j++) curr[j] = (~curr[j]);
      v.push_back(make_pair(i,abs(ant-k)));
  }
  
  sort(v.begin(),v.end(),myfunction);
  
  for (int i = 0; i < v.size()/2; i++){
      int ant = k;
      for (int j = v[i].first; j < v[i].first+25; j++) curr[j] = (~curr[j]);
      send();
      if (k < ant) for (int j = v[i].first; j < v[i].first+25; j++) curr[j] = (~curr[j]);
      
      ant = k;
      for (int j = v[i].first+25; j < v[i].first+50; j++) curr[j] = (~curr[j]);
      send();
      if (k < ant) for (int j = v[i].first+25; j < v[i].first+50; j++) curr[j] = (~curr[j]);
  }
}

int main ()
{
  srand(1234);

  for (int i = 0; i < TAM; i++){
    curr[i] = rand()%2;
    disc[i] = 0;
  }
  send ();
  
  test();

  return 0;
}
