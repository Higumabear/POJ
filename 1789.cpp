// Time-stamp: <Sun Aug 07 17:36:45 東京 (標準時) 2016>
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

char c[2001][8];
int d[2001][2001];

int prim(int V){
  vector<int> mincost(V, INF);
  vector<int> used(V, false);
  mincost[0] = 0;
  int res = 0;
  
  while(true){
    int v = -1;
    for(int u = 0; u < V; u++){
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }
    if(v == -1) break;
    used[v] = true;
    res += mincost[v];
    for(int u = 0; u < V; u++)
      mincost[u] = min(mincost[u], d[v][u]);
  }
  return res;
}

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N), N){
    FILL(d, INF);
    for(int i = 0; i < N; i++) scanf("%s", c[i]);
    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N; j++){
	int cnt = 0;
	for(int k = 0; k < 7; k++) 
	  cnt += (c[i][k] != c[j][k]);
	d[i][j] = d[j][i] = cnt;
      }
    }
    printf("The highest possible quality is 1/%d.\n", prim(N));
  }
  return 0;
}
