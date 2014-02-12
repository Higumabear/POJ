#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> A;

ll merge_count(vector<int> &a){
  int n = a.size();
  if(n <= 1) return 0;

  ll cnt = 0;
  vector<int> b(a.begin(), a.begin() + n / 2);
  vector<int> c(a.begin() + n / 2, a.end());

  cnt += merge_count(b);
  cnt += merge_count(c);

  int ai = 0, bi = 0, ci = 0;
  while(ai < n){
    if(bi < b.size() && (ci == c.size() || b[bi] <= c[ci])){
      a[ai++] = b[bi++];
    }else{
      cnt += n / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return cnt;
}

int main()
{
  int n, p;
  while(1){
    cin >> n;
    if(n == 0) return 0;
    for(int i = 0; i < n; i++){
      cin >> p;
      A.push_back(p);
    }
    cout << merge_count(A) << endl;
    A.clear();
  }
  return 0;
}