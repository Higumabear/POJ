// Time-stamp: <Thu Mar 09 23:28:31 東京 (標準時) 2017>
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

int dp[1001][1001];

int rec(int l, int r, vector<int> &d){
  if(l >= r) return 0;
  if(dp[l][r] != -INF) return dp[l][r];
  
  int u = 0, v = 0;
  if(d[l + 1] >= d[r])
    u = rec(l + 2, r, d) + d[l] - d[l + 1];
  else
    u = rec(l + 1, r - 1, d) + d[l] - d[r];

  if(d[l] >= d[r - 1])
    v = rec(l + 1, r - 1, d) + d[r] - d[l];
  else
    v = rec(l, r - 2, d) + d[r] - d[r - 1];

  return dp[l][r] = max(u, v);
}

int main(int argc, char **argv){
  int N, idx = 0;
  while(cin >> N, N){
    vector<int> d(N);
    FILL(dp, -INF);
    for(int i = 0; i < N; i++)
      scanf("%d", &d[i]);
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",
	   ++idx, rec(0, N - 1, d));
  }
  return 0;
}
