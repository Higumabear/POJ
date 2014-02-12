#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 20000;

int N, L[MAX_N];

int main()
{
  cin >> N;
  priority_queue<int, vector<int>, greater<int> > Q;
  for(int i = 0; i < N; i++) cin >> L[i];
  for(int i = 0; i < N; i++){
    Q.push(L[i]);
  }

  ll res = 0;
  while(Q.size() > 1){
    int l1 = Q.top(); Q.pop();
    int l2 = Q.top(); Q.pop();
    res += (l1 + l2);
    Q.push(l1 + l2);
  }
  cout << res << endl;
  return 0;
}