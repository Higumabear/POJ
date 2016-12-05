// Time-stamp: <Mon Nov 07 22:06:44 東京 (標準時) 2016>
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

double d[101][101];//辺コスト。辺がなければINF

double prim(int V){
  vector<double> mincost(V, 1e100);
  vector<int> used(V, false);
  mincost[0] = 0;
  double res = 0;
  
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
  int N; cin >> N;
  vector<pair<double, double> > p(N);
  for(int i = 0; i < N; i++)
    scanf("%lf %lf", &p[i].first, &p[i].second);
  for(int i = 0; i < N; i++)
    for(int j = i; j < N; j++)
      d[i][j] = d[j][i] = hypotf(p[i].first - p[j].first,
				p[i].second - p[j].second);
  printf("%.2f\n", prim(N));
  return 0;
}
