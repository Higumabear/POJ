// Time-stamp: <Fri Mar 03 23:05:23 東京 (標準時) 2017>
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

struct edge{
  int to, cost;
};

vector<edge> g[40001];
int dist[40001];

void dfs(int cur, int prev, int cost){
  dist[cur] = cost;
  for(int i = 0; i < g[cur].size(); i++)
    if(g[cur][i].to != prev) 
      dfs(g[cur][i].to, cur, cost + g[cur][i].cost);
}

int main(int argc, char **argv){
  int V, E;
  scanf("%d %d", &V, &E);

  for(int i = 0; i < E; i++){
    int s, t, c; char dir;
    scanf("%d %d %d %c", &s, &t, &c, &dir);
    g[s - 1].push_back((edge){t - 1, c});
    g[t - 1].push_back((edge){s - 1, c});
  }

  fill(dist, dist + V, 0);
  dfs(0, -1, 0);;

  int u = max_element(dist, dist + V) - dist;
  fill(dist, dist + V, 0);
  dfs(u, -1, 0);
  printf("%d\n", *max_element(dist, dist + V));
  return 0;
}
