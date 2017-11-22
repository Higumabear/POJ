// Time-stamp: <Wed Aug 02 00:34:00 東京 (標準時) 2017>
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

int p[6001], dp[6001][2];
vector<vector<int> >g;

int dfs(int cur, bool prevuse){
  if(dp[cur][prevuse] != -1) return dp[cur][prevuse];
  
  int ret = 0;
  if(prevuse){
    for(int i = 0; i < g[cur].size(); i++){
      int next = g[cur][i];
      ret += dfs(next, false);
    }
  }else{
    int s1 = 0, s2 = max(p[cur], 0);
    for(int i = 0; i < g[cur].size(); i++){
      int next = g[cur][i];
      s1 += dfs(next, false);
      s2 += dfs(next, true);
    }
    ret = max(s1, s2);
  }
  return dp[cur][prevuse] = ret;
}

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  g.clear();
  g.resize(N);
  for(int i = 0; i < N; i++) scanf("%d", p + i);

  int a, b;
  vector<bool> f(N, false);
  for(int i = 0; i < N - 1; i++){
    scanf("%d %d", &a, &b);
    g[b - 1].push_back(a - 1);
    f[a - 1] = true;
  }
  int s;
  for(s = 0; s < N; s++) if(!f[s]) break;
  FILL(dp, -1);
  //dump(s);

  printf("%d\n", dfs(s, false));
  // for(int i = 0; i < N; i++)
  //   printf("%d : %d %d\n", i, dp[i][0], dp[i][1]);
  scanf("%d %d", &a, &b);
  return 0;
}
