// Time-stamp: <Wed Mar 29 01:01:18 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

int sz(int n, int usedword){
  if(n == 0) return 1;
  int res = 1;
  int num = 26 - usedword;
  for(int i = num; i > num - n; i--)
    res = res * i / (num + 1 - i);
  return res;
}

int main(int argc, char **argv){
  string s; cin >> s;
  
  for(int i = 0; i < s.size() - 1; i++){
    if(s[i] >= s[i + 1]){
      cout << "0" << endl;
      return 0;
    }
  }
  int res = 1;
  for(int i = 1; i < s.size(); i++)
    res += sz(i, 0);
  
  int used = -1;
  for(int i = 0; i < s.size(); i++){
    int u = s[i] - 'a';
    for(int j = u; j >= used + 2; j--)
      res += sz(s.size() - i - 1, j);
    used = u;
  }
  cout << res << endl;
  return 0;
}
