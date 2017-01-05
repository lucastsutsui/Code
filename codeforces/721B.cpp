#include <bits/stdc++.h>
using namespace std;

bool mycmp (const string &a, const string &b){
  return a.size() < b.size();
}

int main ()
{
  int n, k, t1, t2;
  string str, correct;
  vector<string> v;

  cin >> n >> k;

  for (int i = 0; i < n; i++){
    cin >> str;
    v.push_back(str);
  }

  sort(v.begin(), v.end(), mycmp);

  t1 = t2 = 0;

  cin >> correct;
  
  for (int i = 0; i < n; i++){
    t1++;
    if (v[i].size() == correct.size())
      break;
    if (i % k == k-1) t1+=5;
  }

  for (int i = 0; i < n; i++){
    t2++;
    if ((v[i].size() == correct.size() && i+1 < n && v[i+1].size() > correct.size()) || (i==n-1))
      break;
    if (i % k == k-1) t2+=5;
  }

  cout << t1 << ' ' << t2 << endl;

  return 0;
}
