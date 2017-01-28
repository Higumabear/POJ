// Time-stamp: <Wed Jan 18 22:04:54 東京 (標準時) 2017>
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
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int n;
int x[11], y[11];
int dp[1 << 10][10];

int rec(int S, int idx){
  if(__builtin_popcount(S) == n + 1 && idx == 0) return 0;
  if(dp[S][idx] != -1) return dp[S][idx];

  int ret = INF;
  for(int i = 0; i < n + 1; i++){
    if(S >> i & 1) continue;
    ret = min(ret, rec(S | (1 << i), i) 
	      + abs(x[i] - x[idx]) + abs(y[i] - y[idx]));
  }
  return dp[S][idx] = ret;
}

int main(int argc, char **argv){
  int t;
  cin >> t;
  while(t--){
    int h, w;
    cin >> h >> w;
    cin >> x[0] >> y[0];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i + 1] >> y[i + 1];
    FILL(dp, -1);
    cout << "The shortest path has length " << rec(0, 0) << endl;
  }
  return 0;
}
