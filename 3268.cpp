// Time-stamp: <Mon Feb 13 00:37:02 東京 (標準時) 2017>
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
  int from, to, cost;
  edge() {}
  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

//vector<vector<edge> > g;
int en[1010];
edge g[1010][1010];

inline void add_edge(int from, int to, int cost){//2way
  g[from][en[from]++] = edge(from, to, cost);
  //g[from].push_back(edge(from, to, cost));
}

//distに最短距離が入る。経路がない場合はINF。
//prev_nodeにそのノードの一つ前のノードが入る。
//idx == prev_node[idx] となったら始点
int prev_node[1010];
int dist[1010];
int dijkstra(int s, int t){
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(-2, s, 0));
  fill(dist, dist + 1010, INF);
  fill(prev_node, prev_node + 1010, -1);
  
  dist[s] = 0;
  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    if(prev_node[e.to] != -1) continue;

    prev_node[e.to] = e.from;
    //for(int i = 0; i < g[e.to].size(); i++){
    for(int i = 0; i < en[e.to]; i++){
      edge f = g[e.to][i];
      if(dist[f.to] > dist[e.to] + f.cost){
	dist[f.to] = dist[e.to] + f.cost;
	Q.push(edge(f.from, f.to, f.cost + dist[e.to]));
      }
    }
  }  
  return dist[t];
}

int d[1010];

int main(int argc, char **argv){
  int N, M, r;
  scanf("%d %d %d", &N, &M, &r);
  r--;
  //g.resize(N);
  FILL(en, 0);
  for(int i = 0; i < M; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a - 1, b - 1, c);
  }
  int ans = 0;
  dijkstra(r, 1);
  vector<int> fromr;
  for(int i = 0; i < N; i++)
    fromr.push_back(dist[i]);

  FILL(d, -1);
  for(int i = 0; i < N; i++){
    if(d[i] != -1) continue;
    d[i] = dijkstra(i, r);
    // for(int v = r; prev_node[v] != -2; v = prev_node[v]){
    //   d[v] = dist[r] - dist[v];
    // }
  }
  for(int i = 0; i < N; i++){
    ans = max(ans, d[i] + fromr[i]);
  }
  printf("%d\n", ans);
}
