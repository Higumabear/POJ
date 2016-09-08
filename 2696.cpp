// Time-stamp: <Mon Jun 06 21:36:50 東京 (標準時) 2016>
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

int a, b, c, d, e, f, g, h, i;
int memo[1100];

int rec(int idx){
  if(idx == 0) return a;
  if(idx == 1) return b;
  if(idx == 2) return c;
  if(memo[idx] != -1) return memo[idx];

  int ret = 0;
  if(idx & 1)
    ret = (d * rec(idx - 1) + e * rec(idx - 2) - f * rec(idx - 3) + 1000000 * g) % g;
  else
    ret = (f * rec(idx - 1) - d * rec(idx - 2) + e * rec(idx - 3) + 1000000 * h) % h;
  
  return memo[idx] = ret;
}

int main(int argc, char **argv){
  int N;
  cin >> N;
  while(N--){
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    memset(memo, -1, sizeof(memo));
    cout << rec(i) << endl;
  }
  return 0;
}
