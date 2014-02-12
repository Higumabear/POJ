#include <iostream>
#include <cstdio>
//#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

vector<int> univ[100001];
ll v[100001], dp[100001];
ll ans, sum;

ll _abs(ll a){
  return a > 0 ? a : -a;
}

void dfs(int to, int from){
  int vv;
  dp[to] = v[to];
  for(int i = 0; i < (int)univ[to].size(); i++){
    vv = univ[to][i];
    if(vv != from){
      dfs(vv, to);
      dp[to] += dp[vv];
      ans = min(_abs(sum - 2 * dp[vv]), ans);
    }
  }
  return;
}

int main(){
  int Cas = 1;
  int N, M;
  while(scanf("%d %d", &N, &M), N | M){
    for(int i = 0; i < 100001; i++)
      univ[i].clear();
   
    ans = 1LL << 60;
    sum = 0;
   
    for(int i = 0; i < N; i++){
      scanf("%lld", &v[i]);
      sum += v[i];
    }
     for(int i = 0; i < M; i++){
      int to, from;
      scanf("%d %d", &to, &from);
      univ[to - 1].push_back(from - 1);
      univ[from - 1].push_back(to - 1);
    }
    dfs(1, -1);
    printf("Case %d: %lld\n", Cas++, ans);
  }
  return 0;
}