// Time-stamp: <Sat Jan 07 23:37:22 東京 (標準時) 2017>
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

int card[101];
ll dp[101][101];
ll rec(int a, int b){
  if(a >= b) return 0;
  if(dp[a][b]) return dp[a][b];
  ll ret = LLINF;
  for(int i = a; i < b; i++)
    ret = min<ll>(ret, card[a - 1] * card[i] * card[b] + rec(a, i) + rec(i + 1, b));
  return dp[a][b] = ret;
}
int main(int argc, char **argv){
  FILL(dp, 0);
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> card[i];
  cout << rec(1, n - 1) << endl;
  return 0;
}