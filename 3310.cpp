// Time-stamp: <Sun Apr 30 00:54:27 東京 (標準時) 2017>
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

bool cyclic;
int deg[101], dist[101];
vector<int> g[101];

void rec(int idx, int prev, int d){
  if(dist[idx] < d){
    cyclic = true;
    return;
  }
  dist[idx] = d;
  for(int i = 0; i < g[idx].size(); i++){
    if(g[idx][i] == prev) continue;
    rec(g[idx][i], idx, d + 1);
  }
}

int main(int argc, char **argv){
  int n, e, num = 1;
  while(scanf("%d", &n), n){
    cyclic = false;
    FILL(deg, 0);
    for(int i = 0; i < n; i++) g[i].clear();

    scanf("%d", &e);
    for(int i = 0; i < e; i++){
      int f, t;
      scanf("%d %d", &f, &t);
      deg[f - 1]++;
      deg[t - 1]++;
      g[f - 1].push_back(t - 1);
      g[t - 1].push_back(f - 1);
    }
    FILL(dist, INF);
    rec(0, -1, 0);
    if(cyclic || count(dist, dist + n, INF)){
      printf("Graph %d is not a caterpillar.\n", num);
    }else{
      int v = max_element(dist, dist + n) - dist;
      FILL(dist, INF);
      rec(v, -1, 0);
      int diameter = *max_element(dist, dist + n);
      
      if(diameter - 2 == n - count(deg, deg + n, 1) - 1)
	printf("Graph %d is a caterpillar.\n", num);
      else
	printf("Graph %d is not a caterpillar.\n", num);
    }
    num++;
  }
  return 0;
}
