#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = (1 << 31) - 1;

vector<int> g[5000], rg[5000];
int dp[5000], dp2[5000];
int sum[5000];

int main(int argc, char **argv){
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    g[u - 1].push_back(v - 1);
    rg[v - 1].push_back(u - 1);
  }

  dp2[N - 1] = 1;
  for(int i = N - 1; i >= 0; i--)
    for(int j = 0; j < rg[i].size(); j++)
      dp2[rg[i][j]] += dp2[i];

  int ans = 0;
  for(int i = 0; i < N; i++){
    if(!dp[i]) dp[i] = 1;
    for(int j = 0; j < g[i].size(); j++){
      dp[g[i][j]] += dp[i];
      ans = max(ans, dp[i] * dp2[g[i][j]]);
    }
    
  }
  printf("%d\n", ans);
}
