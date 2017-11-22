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

vector<int> g[2000];
int dp[2000][2];

int rec(int idx, int prev, bool prevuse){
  if(dp[idx][prevuse] != -1) return dp[idx][prevuse];

  int ret = INF;
  if(prevuse){
    int s1 = 0, s2 = 0;
    for(int i = 0; i < g[idx].size(); i++){
      int to = g[idx][i];
      if(to == prev) continue;
      s1 += rec(to, idx, true);
      s2 += rec(to, idx, false);
    }
    ret = min(s1 + 1, s2);
  }else{
    int s3 = 0;
    for(int i = 0; i < g[idx].size(); i++){
      int to = g[idx][i];
      if(to == prev) continue;
      s3 += rec(to, idx, true);
    }
    ret = min(ret, s3 + 1);
  }
  return dp[idx][prevuse] = ret;
}

int main(){
  int V;
  while(scanf("%d", &V) != EOF){
    for(int i = 0; i < 2000; i++) g[i].clear();
    for(int i = 0; i < V; i++){
      int from, k;
      scanf("%d: (%d)", &from, &k);
      for(int j = 0; j < k; j++){
	int to; scanf("%d", &to);
	g[from].push_back(to);
	g[to].push_back(from);
      }
      getchar();
    }
    FILL(dp, -1);
    printf("%d\n", rec(0, -1, true));
  }
  return 0;
}
